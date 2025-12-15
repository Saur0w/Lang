//
// Created by sthap on 15-12-2025.
//

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
        if (current == '\n') line++;
        advance();
        current = peek();
    }

    if (current == '\0') return {TOKEN_EOF, "", line};

    if (current == '{') {
       advance();
        return {TOKEN_LBRACE, "{", line};
    }
    if (current == '}') { advance(); return {TOKEN_RBRACE, "}", line}; }
    if (current == '(') { advance(); return {TOKEN_LPAREN, "(", line}; }
    if (current == ')') { advance(); return {TOKEN_RPAREN, ")", line}; }
    if (current == ':') { advance(); return {TOKEN_COLON, ":", line}; }
    if (current == ';') { advance(); return {TOKEN_SEMICOLON, ";", line}; }
    if (current == '=') { advance(); return {TOKEN_ASSIGN, "=", line}; }
    if (current == '+') { advance(); return {TOKEN_PLUS, "+", line}; }
    if (current == '.') { advance(); return {TOKEN_DOT, ".", line}; }

    if (isalpha(current)) {
        std::string text;
        while (isalnum(peek()) || peek() == '_') {
            text += advance();
        }
        if (text == "class") return {TOKEN_CLASS, text, line};
        if (text == "public") return {TOKEN_PUBLIC, text, line};
        if (text == "int") return {TOKEN_INT, text, line};
    }