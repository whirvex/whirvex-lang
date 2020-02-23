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
#include "srcfile.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct srcfile_ {
	FILE* file;
} srcfile;

int srcfile_open(srcfile** srcFile, const char* path) {
	FILE* file;
	errno_t open = fopen_s(&file, path, "r");
	if (open != 0) {
		return SRCFILE_OPEN_FAILURE;
	}
	(*srcFile) = malloc(sizeof(srcfile));
	(*srcFile)->file = file;
	return SRCFILE_SUCCESS;
}

int srcfile_nextchar(srcfile* srcFile) {
	return fgetc(srcFile->file);
}

int srcfile_lastchar(srcfile* srcFile, bool pushback) {
	fseek(srcFile->file, -1, SEEK_CUR);
	int previous = fgetc(srcFile->file);
	if(pushback == true) {
		fseek(srcFile->file, -1, SEEK_CUR);
	}
	return previous;
}

void srcfile_rollback(srcfile* srcFile, int amount) {
	fseek(srcFile->file, -amount, SEEK_CUR);
}

void srcfile_push(srcfile* srcFile, int amount) {
	fseek(srcFile->file, amount, SEEK_CUR);
}

int srcfile_charat(srcfile* srcFile, int index) {
	int current = ftell(srcFile->file);
	fseek(srcFile->file, index, SEEK_SET);
	int at = fgetc(srcFile->file);
	fseek(srcFile->file, current, SEEK_SET);
	return at;
}

int srcfile_index(srcfile* srcFile) {
	return ftell(srcFile->file);
}