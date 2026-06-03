#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <string>
#include <fstream>
#include <cstring>
#include <regex>
#include <iostream>

bool is_integer(const std::string&);
bool is_double(const std::string&);
bool is_cell(const std::string&);

std::string check(const std::string&);

std::string extract_string(std::string, const char);
std::string extract_string(std::string, std::string, std::string);
//std::string removeWhiteSpaces(Menu&);
std::string removeWS(const std::string);

size_t get_rows(std::fstream&);
size_t get_columns(std::fstream&);

void separate(void);
void separate_with_automata(void);

bool is_string(const std::string&);

bool valid_expr(const std::string&, const size_t&, const size_t&);
std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str)

#endif