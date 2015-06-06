//
//  repository.h
//  php-libgit2
//
//  Created by Johannes Hahn on 06.06.15.
//  Copyright (c) 2015 Johannes Hahn. All rights reserved.
//

#ifndef __php_libgit2__repository__
#define __php_libgit2__repository__

#include "common.h"

namespace PhpLibgit2
{
    class Repository : public Php::Base
    {
        private:
        
            const char *_path;
            int _is_bare;
            
        
        
        public:
        
            Repository();
            virtual ~Repository();
        
            Php::Value getIsBare() const;
            Php::Value getPath() const;
            Php::Value php_git_repository_init(Php::Parameters &params);
            Php::Value php_git_repository_open(Php::Parameters &params);
            Php::Value php_git_repository_open_bare(Php::Parameters &params);
            Php::Value php_git_repository_is_bare();
        
        
    };
}


#endif /* defined(__php_libgit2__repository__) */
