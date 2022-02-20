/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"


int main()
{

try{

    using namespace Graph_lib;



    Point tl {100, 50};

    Simple_window win {tl, 1000, 800, "Window"};

    // Négyzetrács

    Lines grid;
    int x_size = 800;
    int y_size = 800;
    


    for (int i = 100; i <= x_size; i+=100)
    {
        grid.add(Point(i,0), Point(i, y_size));
        grid.add(Point(0,i), Point(x_size, i));
    }


    win.attach(grid);


    //Négyzetek az átlóra

    Vector_ref<Rectangle> v;



    for (int i = 0; i < x_size; i+=100)
    {
        v.push_back(new Rectangle{Point{i,i}, 100, 100});
        
    }

    for (int i = 0; i < v.size(); ++i)
    {
        v[i].set_fill_color(Color::red);
        win.attach(v[i]);
    }



    //Három kép

    Image pic1 {Point{0, 300}, "pic.jpeg"};
    Image pic2 {Point{600, 0}, "pic.jpeg"};
    Image pic3 {Point{200, 500}, "pic.jpeg"};

    win.attach(pic1);
    win.attach(pic2);
    win.attach(pic3);


    win.wait_for_button();



    //Kép random helyezgetése 10 alkalommal

    srand((unsigned)time(0)); 


    for (int i = 0; i < 10; i++)
    {
        int px = rand() % 8;
        int py = rand() % 8;
        Image pic4 {Point{px*100, py*100}, "pic2.jpg"};
        win.attach(pic4);
        cout << px;
        win.wait_for_button();
    }


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
