#include "String.h"

/* Private methods */

void String::copy(const char* cstring)
{
	len = strlen(cstring);
    cstr = new char[len + 1];
    strcpy(cstr, cstring);
}

/* Private methods */



/* Constructors, destructors, operator= */

String::String() { len = 0; copy(""); } /* default (1) */

String::String(const String& other) { copy(other.cstr); } /* copy (2) */

String::String(const String& other, size_t pos, size_t length) /* substring (3) */
{
	char* tmp = other.cstr + pos;
	
	if (strlen(tmp) < length) len = strlen(tmp);
	else len = length;

	cstr = new char[len + 1];
	
	char* cpy = cstr;
	
	while (length--) *cpy++ = *tmp++; 
	
	*cpy = '\0';
}

String::String(const char* cstring) { copy(cstring); } /* from c-string (4) */

String::String(const char* cstring, size_t length) /* from buffer (5) */
{
	len = strlen(cstring);
	copy(cstring);
}

String::String(size_t length, char symbol) /* fill (6) */
{
	len = length;
	cstr = new char[len + 1];
	
	char* tmp = cstr;
	while (length--) *tmp++ = symbol;
	
	*tmp = '\0';
}

#if 0
template <class InputIterator>
String::String(InputIterator, InputIterator) /* range (7) */ {}
String::String(initializer_list<char>) /* initializer list (8) */ {}
String::String(String&&) noexcept /* move (9) */ {}
#endif

String::~String() { delete [] cstr; }

String& String::operator= (const String& other) /* String (1) */
{
	if(this != &other)
	{
    	delete [] cstr;
    	copy(other.cstr);
	}
	
    return *this;
}

String& String::operator= (const char* cstring) /* c-string (2) */
{
	if (strcmp(cstr, cstring) != 0)
	{
		delete [] cstr;
		copy(cstring);
	}
	
	return *this;
}

String& String::operator= (char symbol) /* character (3) */
{
	if (cstr != nullptr) delete [] cstr;
	
	len = 1;
	
	cstr = new char[len + 1];
	
	cstr[0] = symbol;
	cstr[1] = '\0';
	
	return *this;
}

#if 0
String& String::operator= (initializer_list<char> init_list) { return *this; } /* initializer list (4) */
String& String::operator= (String&& cstr) noexcept { return *this; } /* move (5) */
#endif

/* Constructors, destructors, operator= */



/* Capacity */

size_t String::size(void) const noexcept { return len; }

size_t String::length(void) const noexcept { return len; }

size_t String::max_size(void) const noexcept { return -1; }

void String::resize (size_t length)
{
	if (length < len)
	{
		char* tmp = new char[length + 1];
		strcpy(tmp, cstr);
		
		delete [] cstr;
		copy(tmp);
		
		delete [] tmp;
	}
	else if (length > len)
	{
		char* tmp = new char[len + 1];
		strcpy(tmp, cstr);		
		
		delete [] cstr;
		len = length;
		cstr = new char[len + 1];
		
		strcpy(cstr, tmp);
		
		delete [] tmp;
	}
}

void String::resize (size_t length, char symbol)
{
	if (cstr != nullptr) delete [] cstr;
	
	len = length;
	cstr = new char[len + 1];
	
	size_t i = 0;
	while (i != length) cstr[i++] = symbol; 
	
	cstr[len] = '\0';
}

size_t String::capacity(void) const noexcept { return len; }

void String::reserve (size_t length) {}

void String::clear(void) noexcept 
{
	if (cstr != nullptr) delete [] cstr;
	
	len = 0;
	copy("");
}

bool String::empty(void) const noexcept { return len == 0; } /* cstr will never be nullptr, cause in the default constructor we have alreadt allocated memory */

void String::shrink_to_fit(void) {}
	
/* Capacity */
    


/* Element access */
char& String::operator[] (size_t index)
{
	assert(cstr != nullptr && len > 0);
	assert(index >= 0 && index <= len - 1);
	
	return *(cstr + index);
}

const char& String::operator[] (size_t index) const
{
	assert(cstr != nullptr && len > 0);
	assert(index >= 0 && index <= len - 1);
	
	return *(cstr + index);
}

char& String::at(size_t index)
{
	assert(cstr != nullptr && len > 0);
	assert(index >= 0 && index <= len - 1);
	
	return *(cstr + index);
}

const char& String::at(size_t index) const
{
	assert(cstr != nullptr && len > 0);
	assert(index >= 0 && index <= len - 1);
	
	return *(cstr + index);
}

char& String::back(void) 
{
	assert(cstr != nullptr && len > 0);
	return *(cstr + len - 1);
}
const char& String::back(void) const 
{ 
	assert(cstr != nullptr && len > 0);
	return *(cstr + len - 1);
}

char& String::front(void)
{ 
	assert(cstr != nullptr && len > 0);
	return *cstr;
}
const char& String::front(void) const
{ 
	assert(cstr != nullptr && len > 0);
	return *cstr;
}

/* Element access */


   
/* Modifiers */

String& String::operator+= (const String& other) /* String (1) */
{
    String temp;
    temp.cstr = new char[len + other.length() + 1];
    
    for(size_t i = 0; i < len; i++) temp.cstr[i] = cstr[i];
    
    for(size_t i = len; i < len + other.len; i++) temp.cstr[i] = other.cstr[i - len];

    delete [] cstr;
    
    len += other.len;
    cstr = new char[len + 1];
    
    for (size_t i = 0; i < len; i++) cstr[i] = temp.cstr[i];
    
    return *this;
}

String& String::operator+= (const char* cstring) /* c-ctring (2) */
{
    String temp;
    temp.cstr = new char[len + strlen(cstring) + 1];
    
    for (size_t i = 0; i < len; i++) temp.cstr[i] = cstr[i];
    
    for (size_t i = len; i < len + strlen(cstring) + 1; i++) temp.cstr[i] = cstring[i - len];
    
    delete [] cstr;
    
    len += strlen(cstring);
    cstr = new char[len + 1];
    
    for (size_t i = 0; i < len; i++) cstr[i] = temp.cstr[i];
    
    return *this;
}

String& String::operator+= (char symbol) /* character (3) */
{
    String temp;
    temp.cstr = new char[len + 2];
    
    for (size_t i = 0; i < len; i++) temp.cstr[i] = cstr[i];
    temp.cstr[len] = symbol;
    
    delete [] cstr;
    
    cstr = new char[++len + 1];
    
    for (size_t i = 0; i < len; i++) cstr[i] = temp.cstr[i];
    
    return *this;
}

//String& operator+= (initializer_list<char>) /* initializer list (4) */  {}
   
String& String::append(const String& other) /* String (1) */ { return (*this) += other; }

String& String::append(const String& other, size_t subpos, size_t sublen) /* substring (2) */
{ return (*this) += String(other, subpos, sublen); }

String& String::append(const char* cstring) /* c-string (3) */ { return (*this) += cstring; }

String& String::append(const char* cstring, size_t length) /* buffer (4) */ 
{ return (*this) += String(cstring, length); }

String& String::append(size_t length, char symbol) /* fill (5) */
{ return (*this) += String(length, symbol); }

#if 0
template <class InputIterator>
String& append (InputIterator first, InputIterator last); /* range (6) */
	
String& append (initializer_list<char> il); /* initializer list(7) */
#endif
   
void String::push_back(char symbol) { *this += symbol; }

String& String::assign(const String& other) /* String (1) */ { return (*this) = other; }

String& String::assign(const String& other, size_t subpos, size_t sublen) /* substring (2) */ 
{ return (*this) = String(other, subpos, sublen); }

String& String::assign(const char* cstring) /* c-String (3) */ { return (*this) = String(cstring); }

String& String::assign(size_t length, char symbol) /* fill (5) */ { return (*this) = String(length, symbol); }

//template <class InputIterator>
//String& assign(InputIterator first, InputIterator last); /* range (6) */

//String& assign(initializer_list<char> il); /* initializer list(7)	 */
//String& assign(String&& str) noexcept; /* move (8) */

String& String::insert(size_t length, const String& other) /* String (1) */
{ return *this; }

String& String::insert(size_t n, const String& other, size_t k , size_t m) /* substring (2) */
{ return *this; }

String& String::insert(size_t n , const char* cstring) /* c-string (3) */
{ return *this; }

String& String::insert(size_t n, const char* cstring, size_t m) /* buffer (4) */
{ return *this; }

String& String::insert(size_t i, size_t j, char symbol) /* fill (5) */
{ return *this; }

#if 0
iterator insert(const_iterator, size_t, char); /*  */
iterator insert(const_iterator, char); /* single character (6) */
template <class InputIterator>
iterator insert(iterator, InputIterator, InputIterator); /* range (7) */
String& insert(const_iterator, initializer_list<char>); /* initializer list (8) */
#endif

String& String::erase(size_t pos, size_t length) /* sequence (1) */
{ return *this; }
//iterator erase(const_iterator); /* character (2) */
//iterator erase(const_iterator, const_iterator); /* range (3) */

void String::swap(String& other)
{
	String tmp(other);
	other = *this;
	*this = tmp;
}

void String::pop_back(void)
{
	if (len == 0) return;
		
	len--;
	*this = String(cstr, len);
}
	
/* Modifiers */

/* String operations */
const char* String::c_str(void) const noexcept { return cstr; }
const char* String::data(void) const noexcept { return cstr; }
//allocator<char> get_allocator() const noexcept;
size_t String::copy(char* cstring, size_t len, size_t pos) const
{
	size_t i = 0, tmp = len;
	while (tmp--) cstring[i++] = cstr[pos++];
	
	return len - tmp;
}

size_t String::find(const String& other, size_t m) const noexcept /* String (1) */
{ return 0; }

size_t String::find(const char* cstring, size_t length) const /* c-string (2) */
{ return 0; }

size_t String::find(const char* cstring, size_t m, size_t n) const /* buffer (3) */
{ return 0; }

size_t String::find(char symbol, size_t pos) const noexcept  /* character (4) */
{ return 0; }
	
size_t String::rfind(const String& other, size_t m) const noexcept /* String (1) */ 
{ return 0; }

size_t String::rfind (const char* cstring, size_t m) const /* c-string (2) */ 
{ return 0; }

size_t String::rfind (const char* cstring, size_t m, size_t n) const /* buffer (3) */
{ return 0; }

size_t String::rfind (char symbol, size_t pos) const noexcept /* character (4) */
{ return 0; }
	
size_t String::find_first_of (const String& other, size_t n) const noexcept /* String (1) */
{ return 0; }

size_t String::find_first_of (const char* s, size_t n) const /* c-String (2) */
{ return 0; }

size_t String::find_first_of (const char* s, size_t n, size_t k) const /* buffer (3) */
{ return 0; }

size_t String::find_first_of (char s, size_t n) const noexcept /* character (4) */
{ return 0; }


	
size_t String::find_last_of (const String& other, size_t n) const noexcept /* String (1) */ 
{ return 0; }

size_t String::find_last_of (const char* s, size_t n) const /* c-String (2) */
{ return 0; }

size_t String::find_last_of (const char* s, size_t m, size_t n) const /* buffer (3) */
{ return 0; }

size_t String::find_last_of (char s, size_t n) const noexcept /* character (4) */
{ return 0; }

	
size_t String::find_first_not_of (const String& o, size_t n) const noexcept /* String (1) */
{ return 0; }

size_t String::find_first_not_of (const char* s, size_t n) const /* c-String (2) */
{ return 0; }

size_t String::find_first_not_of (const char* s, size_t m, size_t n) const /* buffer (3) */
{ return 0; }

size_t String::find_first_not_of (char s, size_t n) const noexcept /* character (4) */
{ return 0; }


	
size_t String::find_last_not_of (const String& o, size_t n) const noexcept /* String (1) */
{ return 0; }

size_t String::find_last_not_of (const char* s, size_t n) const /* c-String (2) */
{ return 0; }

size_t String::find_last_not_of (const char* s, size_t n, size_t m) const /* buffer (3) */
{ return 0; }

size_t String::find_last_not_of (char s, size_t n) const noexcept /* character (4) */
{ return 0; }


String String::substr(size_t pos, size_t len) const /* get substring between two indexes */
{ return String(*this, pos, len); }


int String::compare (const String&) const noexcept /* String (1) */
{ return 1; }

int String::compare (size_t, size_t, const String&) const /* substrings (2) */
{ return 1; }

int String::compare (size_t n, size_t m, const String& o, size_t t, size_t d) const /* substrings (2) */
{ return 1; }
	
int String::compare (const char* s) const /* c-String (3) */
{ return 1; }

int String::compare (size_t m, size_t n, const char* s) const /* c-String (3) */
{ return 1; }

int String::compare (size_t j, size_t m, const char* s, size_t n) const /* buffer (4) */
{ return 1; }

/* Member constants */
static const size_t npos = -1;
	
/* Non-member function overloads */
#if 0
//operator+
String operator+(String& str1, String& str2) { return str1 += str2; }

String operator+(const String& str1, const String& str2)
{
	String tmp = str1;
	tmp += str2;
	
	return tmp;
}

String operator+(const char* cstr, const String& string)
{
	String tmp(cstr);
	tmp += string;
	
	return tmp;
}

String operator+(const String& string, const char* cstr)
{
	String tmp = string;
	tmp += cstr;
	
	return tmp;
}
	#endif

	/* String (1) */
	String operator+ (const String&, const String&);
	//String operator+ (String&&, String&&);
	//String operator+ (String&&, const String&);
	//String operator+ (const String&, String&&);
	
	/* c-String (2)	*/
	String operator+ (const String&, const char*);
	//String operator+ (String&& lhs, const char*);
	String operator+ (const char*, const String&);
	//String operator+ (const char*, String&&);
	
	/* character (3) */
	String operator+ (const String& lhs, char);
	//String operator+ (String&& lhs, char);
	String operator+ (char, const String&);
	//String operator+ (char, String&&);
	
/* operator == */
bool operator== (const String& lhs, const String& rhs) { return strcmp(lhs.cstr, rhs.cstr) == 0; }
bool operator== (const char* lhs, const String& rhs) { return strcmp(lhs, rhs.cstr) == 0; }
bool operator== (const String& lhs, const char* rhs) { return strcmp(lhs.cstr, rhs) == 0; }

/* operator != */
bool operator!= (const String& lhs, const String& rhs) { return strcmp(lhs.cstr, rhs.cstr) != 0; }
bool operator!= (const char* lhs, const String& rhs) { return strcmp(lhs, rhs.cstr) != 0; }
bool operator!= (const String& lhs, const char* rhs) { return strcmp(lhs.cstr, rhs) != 0; }

/* operator < */
bool operator< (const String& lhs, const String& rhs)
{
	if (lhs.len >= rhs.len) return false;

	size_t tmp_len = lhs.len;
	for (size_t i = 0; i < tmp_len; i++)
		if (lhs.cstr[i] >= rhs.cstr[i]) return false;

	return true;
}

bool operator< (const char* lhs, const String& rhs)
{
	if (strlen(lhs) >= rhs.len) return false;

	size_t tmp_len = strlen(lhs);
	for (size_t i = 0; i < tmp_len; i++)
		if (lhs[i] >= rhs.cstr[i]) return false;

	return true;
}

bool operator< (const String& lhs, const char* rhs) 
{
	if (lhs.len >= strlen(rhs)) return false;

	size_t tmp_len = lhs.len;
	for (size_t i = 0; i < tmp_len; i++)
		if (lhs.cstr[i] >= rhs[i]) return false;

	return true;
}

/* operator <= */
bool operator<= (const String& lhs, const String& rhs)
{
	if (lhs.len >= rhs.len) return false;

	size_t tmp_len = lhs.len;
	for (size_t i = 0; i < tmp_len; i++)
		if (lhs.cstr[i] > rhs.cstr[i]) return false;

	return true;
}

bool operator<= (const char* lhs, const String& rhs)
{
	if (strlen(lhs) >= rhs.len) return false;

	size_t tmp_len = strlen(lhs);
	for (size_t i = 0; i < tmp_len; i++)
		if (lhs[i] > rhs.cstr[i]) return false;

	return true;
}

bool operator<= (const String& lhs, const char* rhs)
{
	if (lhs.len >= strlen(rhs)) return false;

	size_t tmp_len = lhs.len;

	for (size_t i = 0; i < tmp_len; i++)
		if (lhs.cstr[i] >= rhs[i]) return false;

	return true;
}

/* operator > */
bool operator> (const String& lhs, const String& rhs) { return !(lhs < rhs); }
bool operator> (const char* lhs, const String& rhs) { return !(lhs < rhs); }
bool operator> (const String& lhs, const char* rhs) { return !(lhs < rhs); }

/* operator >= */
bool operator>= (const String& lhs, const String& rhs) { return !(lhs <= rhs); }
bool operator>= (const char* lhs, const String& rhs) { return !(lhs <= rhs); }
bool operator>= (const String& lhs, const char* rhs) { return !(lhs <= rhs); }
	
void String::swap(String& lhs, String& rhs)
{
	String tmp(lhs);
	lhs = rhs;
	rhs = tmp;
}

std::istream& operator>>(std::istream& is, String& string)
{
	const size_t buff_size = 100;	
	char buff[buff_size];

	is.get(buff, buff_size, '\n');

	string = String(buff);

	is.clear();
	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return is;
}

std::ostream& operator<<(std::ostream& os, const String& string) { os << string.cstr; return os; }

std::istream& getline(std::istream& is, String& string, char delim)
{
	return is;
}

std::istream& getline(std::istream&& is, String& string, char delim)
{
	return is;
}

std::istream& getline(std::istream& is, String& string)
{
	return is;
}

std::istream& getline(std::istream&& is, String& string)
{
	return is;
}



/* Additional methods */

bool String::contains(const char* substr) const
{
	const char* tmp = substr;
	char* copy = cstr;   

	if (strlen(substr) > len || strlen(substr) == 0) return false; 
	else if (strcmp(cstr, substr) == 0) return true; /* equal strings */
	
	while (*copy)
	{
		if (*tmp == '\0') return true;
		else if (*tmp == *copy) tmp++;
		else tmp = substr;
		copy++;
	}
	
	return *tmp == '\0';
}

bool String::contains(const String& string) const { return contains(string.c_str()); }

/* String String::substr(size_t from, size_t till) const
{
	assert (from >= 0 && from <= len - 1);

	String res = "";

	while (from != till + 1) res += cstr[from++];
	
	return res; 
}
*/

String& String::operator* (size_t mult) { while (mult--) *this += cstr; return *this; }
    
String& String::operator*= (size_t mult) 
{
	if (mult == 0) return (*this) = String();
	else if (mult == 1) return *this;
	
	String tmp;
	
	while (mult--) tmp += (*this) * mult;
	
	return (*this) = tmp;
}

/* Additional methods */
