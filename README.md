# Project
Repository for hosting RTR2017 Final Project

Idea can be found at: https://docs.google.com/document/d/1upf7tDbqfl3QZoaCxFFnFiGu49uX4hOHmkiuX2KfyOI/edit?usp=sharing

The project structure is as follows -

Root

+++ build                               // contains files required for building the solution. e.g. configuration files etc.

+++ common                              // contains files shared throughout the project. This can further include the headers and sources.

        +++ include
    
        +++ src
    
+++ doc                                 // contains project documentation including design, flow of events etc.

+++ prototypes                          // folder containing prototypes created for various approaches grouped by contributions per user

        +++ (username)                         
    
+++ (username1)                         // contains headers and sources contribution from respective users. 

        +++ custom folder structure
    
+++ (username2)

+++

.

.

interfaceregistrar.h                    // main header containing registered classes in order to be included from the top level project file.

main.cpp                                // main project makefile

makefile.txt                            // project makefile


?? anything else?
