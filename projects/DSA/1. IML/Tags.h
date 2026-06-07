#ifndef _TAGS_H_
#define _TAGS_H_

#include <stack>
#include <string>

std::stack<std::string> get_tags(std::string);

void set_tags(std::stack<std::string>&, std::stack<std::string>&, std::stack<std::string>&);

std::stack<std::string> reverse_tags(std::stack<std::string>&);

#endif