//
// Created by sthap on 14-12-2025.
//

#ifndef LANG_LEXER_H
#define LANG_LEXER_H

#include <string>

enum TokenType {
    TOKEN_CLASS,
    TOKEN_PUBLIC,
    TOKEN_INT,
    TOKEN_FN,
    TOKEN_RETURN,

    TOKEN_IDENTIFIER,
    TOKEN_STRING,
    TOKEN_NUMBER,

    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_COLON,
    TOKEN_SEMICOLON,
    TOKEN_ASSIGN,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_DOT,
    TOKEN_COMMA,

    TOKEN_EOF,
    TOKEN_UNKKNOWN
};

struct Token {
    TokenType type;
    std::string value;
    int line;
};

class Lexer {
private:
    std::string src;
    int pos = 0;
    int line = 1;

    char peek();
    char advance();

public:
    Lexer(const std::string& source);
    Token nextToken();
};

#endif //LANG_LEXER_H