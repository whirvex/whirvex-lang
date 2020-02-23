/*
 * __        ___     _                     _
 * \ \      / / |__ (_)_ ____   _______  _| |    __ _ _ __   __ _
 *  \ \ /\ / /| '_ \| | '__\ \ / / _ \ \/ / |   / _` | '_ \ / _` |
 *   \ V  V / | | | | | |   \ V /  __/>  <| |__| (_| | | | | (_| |
 *    \_/\_/  |_| |_|_|_|    \_/ \___/_/\_\_____\__,_|_| |_|\__, |
 *                                                          |___/
 *
 * MIT License
 *
 * Copyright (c) 2019-2020 Whirvex Software
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "word_token.h"
#include <stdlib.h>

typedef struct word_token_ {
    token; // Extend token
    char* word;
} word_token;

void word_token_parse(token* token, FILE* file) {
    word_token* wordToken = (word_token*) token;

}

word_token* create_word_token() {
    word_token* allocated = (word_token*) malloc(sizeof(word_token));
    allocated->type = TYPE_WORD_TOKEN;
    allocated->parse = &word_token_parse;
    return allocated;
}