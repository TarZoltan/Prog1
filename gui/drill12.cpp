#include <stdexcept>

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;


int main(){
try
{
    
    Point tl {100, 100};

   
    Simple_window win {tl, 1280, 720, "My window"};


    Image ii {Point{900, 250}, "badge.jpg"};
    win.attach(ii);

    
    Axis xa {Axis::x, Point{0, 360}, 1280, 10, "X axis"};
    Axis ya {Axis::y, Point{640, 720}, 720, 10, "Y axis"};


    win.attach(ya);
    win.attach(xa);

    
    Function sine {sin, 0, 100, Point{640, 360}, 1000, 50, 50};
    sine.set_color(Color::blue);

    Function cose {cos, 0, 100, Point{0, 360}, 1000, 50, 50};
    cose.set_color(Color::red);


    win.attach(sine);
    win.attach(cose);



    Polygon poly;
    poly.add(Point{200, 600});
    poly.add(Point{600, 600});
    poly.add(Point{600, 400});
    poly.add(Point{400, 200});
    poly.add(Point{200, 200});

    poly.set_color(Color::cyan);
    poly.set_style(Line_style(Line_style::dash, 2));


    win.attach(poly);


    Rectangle rg {Point{900, 0}, 100, 100};
    rg.set_fill_color(Color::green);

    Rectangle ry {Point{900, 100}, 100, 100};
    ry.set_fill_color(Color::yellow);

    Rectangle rr {Point{900, 200}, 100, 100};
    rr.set_fill_color(Color::red);


    win.attach(rg);
    win.attach(ry);
    win.attach(rr);




    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 100});

    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);

    Text t {Point(640, 500), "Hello!"};
    t.set_font(Font::times_bold);
    t.set_font_size(20);

    

    Circle c {Point(640, 200), 50};

    Ellipse e {Point(640, 200), 60, 40};

    Mark m {Point(640, 360), 'o'};

   
    win.attach(c);
    win.attach(e);
    win.attach(m);
    win.attach(t);
    win.attach(poly_rect);
    

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