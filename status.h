//
//  status.h
//  php-libgit2
//
//  Created by Johannes Hahn on 05.06.15.
//  Copyright (c) 2015 Johannes Hahn. All rights reserved.
//

#ifndef __php_libgit2__status__
#define __php_libgit2__status__

#include "common.h"


namespace PhpLibgit2
{
    class Status : public Php::Base
    {
    private:
        
        #define MAX_PATHSPEC 8
        
        git_status_list *_gsl = NULL;
 
        struct options {
            git_status_options statusopt;
            const char *repodir;
            char *pathspec[MAX_PATHSPEC];
            int npaths;
            int format;
            int zterm;
            int showbranch;
        };
        
        struct options _gso = { GIT_STATUS_OPTIONS_INIT, "." };
        
    public:
        Status() {
        
            _gso.statusopt.show  = GIT_STATUS_SHOW_INDEX_AND_WORKDIR;
            _gso.statusopt.flags = GIT_STATUS_OPT_INCLUDE_UNTRACKED |
            GIT_STATUS_OPT_RENAMES_HEAD_TO_INDEX |
            GIT_STATUS_OPT_SORT_CASE_SENSITIVELY;
            

        }
        virtual ~Status();
        Php::Value php_git_status_list_entrycount();
        Php::Value php_git_status_list_new();
            
    };
}

#endif /* defined(__php_libgit2__status__) */
