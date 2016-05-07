// 
// $Id: main.cc,v 1.2 2008/05/01 03:56:02 kilpatds Exp $
// GPL.  Copyright 2003, Douglas Kilpatrick.
//
// This file demonstrates how to use the plugin framework in the main
// application.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Plugin"
#include "takesArg.hh"

PLUGIN_BASE()

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, const char *const argv[])
{
    takesArg *p = NULL;

    if (argc != 2) {
	cerr << "Usage: " << argv[0] << " <PluginName>" << endl;
	return EXIT_FAILURE;
    }

    try {
	p = Plugin<takesArg,std::string>::getPlugin(argv[1],"Hello World");
    } catch (std::runtime_error &e) {
	cerr << "Failed to load plugin: " << e.what() << endl;
	exit(EXIT_FAILURE);
    }
    try {
	p = Plugin<takesArg>::getPlugin(argv[1]);
    } catch (std::runtime_error &e) {
	cout << "Expected failure: " << e.what() << ": Success" << endl;
    }

    cout << p->print() << endl;
    return 0;
}



