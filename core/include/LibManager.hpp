/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** LibManager.hpp
*/

#ifndef LIBMANAGER_HPP_
#define LIBMANAGER_HPP_

#include <string>
#include <dlfcn.h>
#include <iostream>
#include "../../exception/include/Exception.hpp"

template <typename T>
class LibManager {
    public:

        typedef T *(*createInterface)();

        
    //-----------lib-handling-----------------------
    static T *openLib(const std::string &pathLib)
    {
        void *lib;
        createInterface pMaker;


        // Ouverture de la librairie
        try {
            std::cout << pathLib << std::endl;
            lib = dlopen(pathLib.c_str(), RTLD_LAZY);
            if(lib == NULL)
            {
                // std::cerr << "dlopen : "<< dlerror() << std::endl;
                throw Exception("Library not found.");
            }

        // Chargement du constructeur
            void *ptn = dlsym(lib, "createInterface");
            if (ptn == NULL)
            {
                std::cerr << "dlsym : " << dlerror() << std::endl;
                throw Exception("Library constructor not found");
            }
            pMaker = (createInterface)ptn;
            T *libobj = pMaker();
            return (libobj);
        } catch (Exception &except) {
            std::cerr << except.getMessage() << std::endl;
            exit(84);
        }
    }

    static void closeLib(T *lib)
    {
        dlclose(lib);
    }

    protected:
    private:
};

#endif /* !LIBMANAGER_HPP_ */
