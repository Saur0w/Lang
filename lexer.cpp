#include "lexer.h"
#include <cctype>
#include <iostream>

Lexer::Lexer(const std::string& source) : src(source) {}

char Lexer::peek() {
    if (pos >= src.length()) return '\0';
    return src[pos];
}

char Lexer::advance() {
    if (pos >= src.length()) return '\0';
    return src[pos++];
}

Token Lexer::nextToken() {
    char current = peek();
    while (current == ' ' || current == '\t' || current == '\n' || current == '\r') {

    }
}