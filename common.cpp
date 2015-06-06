//
//  common.cpp
//  php-libgit2
//
//  Created by Johannes Hahn on 01.06.15.
//  Copyright (c) 2015 Johannes Hahn. All rights reserved.
//

#include "common.h"

git_repository *_git_repository = NULL;

const char* NO_GIT_REPOSITORY = "No git repository loaded";
const int DEBUG_LIBGIT2 = 0;

int check_lg2(int error)
{
    
    if (error < 0) {
        if(DEBUG_LIBGIT2 == 1){
          const git_error *e = giterr_last();
          printf("Error %d/%d: %s\n", error, e->klass, e->message);
        }
        return 0;
    }
    return 1;
}


