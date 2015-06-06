//
//  common.h
//  php-libgit2
//
//  Created by Johannes Hahn on 01.06.15.
//  Copyright (c) 2015 Johannes Hahn. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#include "git2.h"
#include "phpcpp.h"


/**
 * Check libgit2 error code, printing error to stderr on failure and
 * exiting the program.
 */


extern const char* NO_GIT_REPOSITORY;
extern const int DEBUG_LIBGIT2;

extern int check_lg2(int error);
extern git_repository *_git_repository;
