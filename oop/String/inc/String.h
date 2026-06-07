#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>
#include <cassert>
#include <cstring>
#include <limits>

class Iterator;

class String
{
private:
    char* cstr;
    size_t len;
    
private:
	friend class Iterator;
	void copy(const char*);
    
public:
    /* Constructors, destructors, operator= */
	String(); /* default (1) */
	String(const String&); /* copy (2) */
	String(const String&, size_t, size_t = npos); /* substring (3) */
	String(const char*); /* from c-String (4) */
	String(const char*, size_t); /* from buffer (5) */
	String(size_t, char); /* fill (6) */
	
	//template <class InputIterator>
	//String(InputIterator, InputIterator); /* range (7) */
	
	//String(initializer_list<char>); /* initializer list (8) */
	//String(String&&) noexcept; /* move (9) */
    
    ~String();
    
	String& operator= (const String&); /* String (1) */
	String& operator= (const char*); /* c-String (2) */
	String& operator= (char); /* character (3) */
	//String& operator= (initializer_list<char>); /* initializer list (4) */
	//String& operator= (String&&) noexcept; /* move (5) */
	
	/* Iterators */
#if 0
	Iterator begin() noexcept;
	const_iterator begin() const noexcept;

	Iterator end() noexcept;
	const_iterator end() const noexcept;

	reverse_iterator rbegin() noexcept;
	const_reverse_iterator rbegin() const noexcept;

	reverse_iterator rend() noexcept;
	const_reverse_iterator rend() const noexcept;

	const_iterator cbegin() const noexcept;


	const_iterator cend() const noexcept;

	const_reverse_iterator crbegin() const noexcept;
	const_reverse_iterator crend() const noexcept;
#endif

	/* Capacity */
	size_t size(void) const noexcept;
	size_t length(void) const noexcept;
	size_t max_size(void) const noexcept;
	void resize (size_t);
	void resize (size_t, char);
	size_t capacity(void) const noexcept;
	void reserve (size_t = 0);
	void clear(void) noexcept;
	bool empty(void) const noexcept;
	void shrink_to_fit(void);
    
    /* Element access */
    char& operator[] (size_t);
	const char& operator[] (size_t) const;
	
	char& at(size_t);
	const char& at(size_t) const;
	
	char& back(void);
	const char& back(void) const;
	
	char& front(void);
	const char& front(void) const;
    
    /* Modifiers */
	String& operator+= (const String&); /* String (1) */
	String& operator+= (const char*); /* c-String (2) */
	String& operator+= (char); /* character (3) */
	//String& operator+= (initializer_list<char>); /* initializer list (4)	*/
	
	String& append(const String&); /* String (1) */
	String& append(const String&, size_t, size_t = npos); /* substring (2) */
	String& append(const char*); /* c-String (3) */
	String& append(const char*, size_t); /* buffer (4) */
	String& append(size_t, char); /* fill (5) */
	
	//template <class InputIterator>
	//String& append (InputIterator, InputIterator); /* range (6) */
		
	//String& append (initializer_list<char>); /* initializer list(7) */
	
	void push_back(char);
	
		
	String& assign(const String&); /* String (1) */
	String& assign(const String&, size_t, size_t = npos); /* substring (2) */
	String& assign(const char*); /* c-String (3) */
	
	String& assign(size_t, char); /* fill (5) */
	
	//template <class InputIterator>
	//String& assign(InputIterator, InputIterator); /* range (6) */
	
	//String& assign(initializer_list<char>); /* initializer list(7)	 */
	//String& assign(String&&) noexcept; /* move (8) */

	String& insert(size_t, const String&); /* String (1) */
	String& insert(size_t, const String&, size_t, size_t = npos); /* substring (2) */
	String& insert(size_t, const char*); /* c-String (3) */
	String& insert(size_t, const char*, size_t); /* buffer (4) */
	String& insert(size_t,   size_t, char); /* fill (5) */
	//iterator insert(const_iterator, size_t, char); /*  */
	//iterator insert(const_iterator, char); /* single character (6) */
	//template <class InputIterator>
	//iterator insert(iterator, InputIterator, InputIterator); /* range (7) */
	//String& insert(const_iterator, initializer_list<char>); /* initializer list (8) */
		
	String& erase(size_t = 0, size_t = npos); /* sequence (1) */
	//iterator erase(const_iterator); /* character (2) */
	//iterator erase(const_iterator, const_iterator); /* range (3) */

		
	String& replace(size_t, size_t, const String&); /* String (1) */
	//String& replace(const_iterator, const_iterator, const String&); /* String (1) */
	
	String& replace(size_t, size_t, const String&, size_t, size_t = npos); /* substring (2) */
	
	String& replace(size_t, size_t, const char*); /* c-String (3) */
	//String& replace(const_iterator, const_iterator, const char*); /* c-String (3) */
	
	String& replace(size_t, size_t, const char*, size_t); /* buffer (4) */
	//String& replace(const_iterator, const_iterator, const char*, size_t); /* buffer (4) */
	
	String& replace(size_t, size_t, size_t, char); /* fill (5) */
	//String& replace(const_iterator i1, const_iterator i2, size_t n, char c); /* fill (5) */
	
	//template <class InputIterator>
	//String& replace (const_iterator i1, const_iterator i2, InputIterator first, InputIterator last); /* range (6) */
	
	//String& replace (const_iterator, const_iterator, initializer_list<char>); /* initializer list (7) */

	void swap(String&);
	void pop_back(void);
	
	/* String operations */
	const char* c_str(void) const noexcept;
	const char* data(void) const noexcept;
	//allocator<char> get_allocator() const noexcept;
	size_t copy(char*, size_t, size_t = 0) const;
		
	size_t find (const String&, size_t = 0) const noexcept; /* String (1) */
	size_t find (const char*, size_t = 0) const; /* c-String (2) */
	size_t find (const char*, size_t, size_t) const; /* buffer (3) */
	size_t find (char, size_t = 0) const noexcept;  /* character (4) */
	
		
	size_t rfind (const String&, size_t = npos) const noexcept;/* String (1) */ 
	size_t rfind (const char*, size_t = npos) const; /* c-String (2) */ 
	size_t rfind (const char*, size_t, size_t n) const; /* buffer (3) */
	size_t rfind (char, size_t = npos) const noexcept; /* character (4) */
	
		
	size_t find_first_of (const String&, size_t = 0) const noexcept; /* String (1) */
	size_t find_first_of (const char*, size_t = 0) const; /* c-String (2) */
	size_t find_first_of (const char*, size_t, size_t) const; /* buffer (3) */
	size_t find_first_of (char, size_t = 0) const noexcept; /* character (4) */

		
	size_t find_last_of (const String&, size_t = npos) const noexcept; /* String (1) */ 
	size_t find_last_of (const char*, size_t = npos) const; /* c-String (2) */
	size_t find_last_of (const char*, size_t, size_t) const; /* buffer (3) */
	size_t find_last_of (char, size_t = npos) const noexcept; /* character (4) */

		
	size_t find_first_not_of (const String&, size_t = 0) const noexcept; /* String (1) */
	size_t find_first_not_of (const char*, size_t = 0) const; /* c-String (2) */
	size_t find_first_not_of (const char*, size_t, size_t) const; /* buffer (3) */
	size_t find_first_not_of (char, size_t = 0) const noexcept; /* character (4) */

		
	size_t find_last_not_of (const String&, size_t = npos) const noexcept; /* String (1) */
	size_t find_last_not_of (const char*, size_t = npos) const; /* c-String (2) */
	size_t find_last_not_of (const char*, size_t, size_t) const; /* buffer (3) */
	size_t find_last_not_of (char, size_t = npos) const noexcept; /* character (4) */

	String substr(size_t = 0, size_t = npos) const; /* get substring between two indexes */
	
	
	int compare (const String&) const noexcept; /* String (1) */

	int compare (size_t, size_t, const String&) const; /* substrings (2) */
	int compare (size_t, size_t, const String&, size_t, size_t = npos) const; /* substrings (2) */
		
	int compare (const char*) const; /* c-String (3) */
	int compare (size_t, size_t, const char*) const; /* c-String (3) */
	
	int compare (size_t, size_t, const char*, size_t) const; /* buffer (4)	 */

	/* Member constants */
	static const size_t npos = -1;
	
	/* Non-member function overloads */

	/* String (1) */
	friend String operator+ (const String&, const String&);
	//friend String operator+ (String&&, String&&);
	//friend String operator+ (String&&, const String&);
	//friend String operator+ (const String&, String&&);
	
	/* c-String (2)	*/
	friend String operator+ (const String&, const char*);
	//friend String operator+ (String&&, const char*);
	friend String operator+ (const char*, const String&);
	//friend String operator+ (const char*, String&&);
	
	/* character (3) */
	friend String operator+ (const String&, char);
	//friend String operator+ (String&&, char);
	friend String operator+ (char, const String&);
	//friend String operator+ (char, String&&);
	
    /* operator == */
    friend bool operator== (const String&, const String&);
	friend bool operator== (const char*, const String&);
	friend bool operator== (const String&, const char*);
	
	/* operator != */
	friend bool operator!= (const String&, const String& );
	friend bool operator!= (const char*, const String&);
	friend bool operator!= (const String&, const char*);

	/* operator < */
	friend bool operator< (const String&, const String&);
	friend bool operator< (const char*, const String&);
	friend bool operator< (const String&, const char*);

	/* operator <= */
	friend bool operator<= (const String&, const String&);
	friend bool operator<= (const char*, const String&);
	friend bool operator<= (const String&, const char*);

	/* operator > */
	friend bool operator> (const String&, const String&);
	friend bool operator> (const char*, const String&);
	friend bool operator> (const String&, const char*);

	/* operator >= */
	friend bool operator>= (const String&, const String&);
	friend bool operator>= (const char*, const String&);
	friend bool operator>= (const String&, const char*);
	
	void swap(String&, String&);
	
	friend std::istream& operator>> (std::istream&, String&);
	friend std::ostream& operator<< (std::ostream&, const String&);

	/* (1) */
	friend std::istream& getline(std::istream&, String&, char);
	friend std::istream& getline(std::istream&&, String&, char);
	
	/* (2) */
	friend std::istream& getline(std::istream&, String&);
	friend std::istream& getline(std::istream&&, String&);

    /* Additional methods */
    bool contains(const String&) const;
    bool contains(const char*) const;
    
    String& operator*(size_t);
    String& operator*=(size_t);
};
    
#endif
