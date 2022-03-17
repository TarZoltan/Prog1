/*
    g++ Graph.cpp Window.cpp GUI.cpp Simple_window.cpp drill15func.cpp `fltk-config --ldflags --use-images` -o run.out

*/
#include "Simple_window.h"
#include "Graph.h"



    double one(double x) { return 1; }
    double slope(double x) { return x / 2; }
    double square(double x) { return x * x; }
    double sloping_cos(double x) {return cos(x) + slope(x);}


int main()
{

try{

    using namespace Graph_lib;

    constexpr int xmax = 600;
    constexpr int ymax = 600;

    Simple_window win {Point{100, 100}, xmax, ymax, "Function graphs."};



    constexpr int alength = 400;
    constexpr int notch = 20;

    Axis x {Axis::x, Point{100, 300}, alength, notch, "1 == 20 pixels"};
    Axis y {Axis::y, Point{300, 500}, alength, notch, "1 == 20 pixels"};

    x.set_color(Color::red);
    y.set_color(Color::red);

 
    win.attach(x);
    win.attach(y);


    constexpr int min = -10;
    constexpr int max = 11;
    constexpr int numberOfPoints = 400;
    constexpr int xscale = 20;
    constexpr int yscale = 20;

    Point origo{300, 300};

    Function fone {one, min, max, origo, numberOfPoints, xscale, yscale};

    Function fslope {slope, min, max, origo, numberOfPoints, xscale, yscale};
    Text ts2 {Point{300 - alength/2 + min, 300 + ((300 - alength/2 + min))}, "x/2"};

    Function fsquare {square, min, max, origo, numberOfPoints, xscale, yscale};

    Function fcos { cos, min, max, origo, numberOfPoints, xscale, yscale};

    Function fsloping_cos {sloping_cos, min, max, origo, numberOfPoints, xscale, yscale};



    win.attach(fone);
    win.attach(fslope);
    win.attach(ts2);
    win.attach(fsquare);
    win.attach(fcos);
    win.attach(fsloping_cos);



    win.wait_for_button();
}


catch(exception& e){
    cerr << "exception: " << e.what() << endl;
    return 1;
}

catch(...){
    cerr << "exception\n";
    return 2;
}


}
