//
//  main.cpp
//  php-libgit2
//
//  Created by Johannes Hahn on 01.06.15.
//  Copyright (c) 2015 Johannes Hahn. All rights reserved.
//

#include "main.h"
#include "repository.h"
#include "status.h"



/**
 *  tell the compiler that the get_module is a pure C function
 */
extern "C" {
    
    /**
     *  Function that is called by PHP right after the PHP process
     *  has started, and that returns an address of an internal PHP
     *  strucure with all the details and features of your extension
     *
     *  @return void*   a pointer to an address that is understood by PHP
     */
    PHPCPP_EXPORT void *get_module()
    {
        
        static Php::Extension extension_phpLibgit2("php-libgit2", "1.0");
        Php::Namespace namepsace_PhpLibgit2("PhpLibgit2");
        
        
        
    /* ############################################################################################################### */
    /* Repository to PHP - start */
        
        Php::Class<PhpLibgit2::Repository> class_Repository("Repository");
        
        class_Repository.method("getPath", &PhpLibgit2::Repository::getPath);
        class_Repository.method("getIsBare", &PhpLibgit2::Repository::getIsBare);
        
        class_Repository.method("git_repository_init",
                                &PhpLibgit2::Repository::php_git_repository_init,
                                Php::Public,{
                                    Php::ByVal("path", Php::Type::String, true),
                                    Php::ByVal("is_bare", Php::Type::Bool, false)
        });
        
        class_Repository.method("git_repository_open",
                                &PhpLibgit2::Repository::php_git_repository_open,
                                Php::Public, {
                                    Php::ByVal("path", Php::Type::String, false)
        });
        
        class_Repository.method("git_repository_open_bare",
                                &PhpLibgit2::Repository::php_git_repository_open_bare,
                                Php::Public, {
                                    Php::ByVal("path", Php::Type::String, false)
        });
        
        class_Repository.method("git_repository_is_bare", &PhpLibgit2::Repository::php_git_repository_is_bare, Php::Public);
        
        
        namepsace_PhpLibgit2.add(std::move(class_Repository));
        
    /* Repository to PHP - end */
    /* ############################################################################################################### */
        
        
    /* ############################################################################################################### */
    /* Status to PHP - start */
        
        Php::Class<PhpLibgit2::Status> class_Status("Status");
        
        class_Status.method("git_status_list_new", &PhpLibgit2::Status::php_git_status_list_new);
        class_Status.method("git_status_list_entrycount", &PhpLibgit2::Status::php_git_status_list_entrycount);
        
        
        namepsace_PhpLibgit2.add(std::move(class_Status));
        
    /* Status to PHP - end */
    /* ############################################################################################################### */
        
        
        // add the namespace to the extension
        extension_phpLibgit2.add(std::move(namepsace_PhpLibgit2));
        // return the extension
        return extension_phpLibgit2;
    }
}
