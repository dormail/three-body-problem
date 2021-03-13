//
// Created by mmaile on 3/12/21.
//

#include <gtkmm.h>
#include "MyWindow.h"

//int main(int argc, char *argv[]) {
//    	auto app = Gtk::Application::create(argc, argv,
//			"org.gtkmm.examples.base");
//
//	/* construct new window */
//	MyWindow win();
//
//	return app->run(win);
//}

int main(int argc, char *argv[]){
    auto app = Gtk::Application::create(argc, argv,
                                        "org.gtkmm.examples.base");

    /* construct new window */
    MyWindow win(800, 600);

    return app->run(win);
}
