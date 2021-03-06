/**
 * Assignment 3 - IF3260 Grafika Komputer
 */

#include "parsetool.h"

#include "glyph.h"
#include <unistd.h>

#define MAX_X 16
#define MAX_Y 32

void Glyph::Draw (Framebuffer& _buf, int _x, int _y, int _borderColor, int _inColor, bool _main) const {
    for (const Polygon& polygon : polygons) {
        polygon.Draw(_buf, _x, _y);
    }
    //sleep(1);
    //Raster raster(_x,_y,MAX_X,MAX_Y);
    //raster.Coloring(_buf, _borderColor,_inColor,_main);
    // Rastering
//     bool colorize;
//     for (j=0; j< _y; j++){
//         colorize = false;
//         for (i=0; i<_x; i++) {
//             Point point;
//             // If the pixel is line color
//             if (std::find(points.begin(), points.end(), point) != points.end()) {
//                 //Change color
//                 if (!colorize) {
//                     colorize = true;
//                 } else {
//                     colorize = false;
//                 }
//             }

//             buf.Write(_y + j, _x + i, 0xFFFFFF, colorize);
//         }
//     }
    int x = _x;
    int y = _y;
    bool startColor;
    for (y = _y; y < _y + MAX_Y; y++) {
        startColor = false;
        for (x = _x; x < _x + MAX_X; x++) {
            //if (_buf.isColor(y,x,_borderColor,_buf.BUF_MAIN)) {
            if (_buf.isColor(y,x,_borderColor,_main) && !_buf.isColor(y,x+1,_borderColor,_main)) {
            //if (_buf.isColor(y,x,_borderColor,_main) && !_buf.isColor(y,x+1,_borderColor,_main) && !IsExceptionalAllPolygon(x,y)) {
                startColor = !startColor;
                //printf("WOW");
            } else {
                //printf("eksDE\n" );
            }
            if ((startColor) && (!_buf.isColor(y,x,_borderColor,_main))) {
                _buf.Write(y,x,_inColor,_main);
            }
        }
    }
    //sleep(1);
}

istream& operator>> (istream& _is, Glyph& _obj) {
    // Read '{' character.
    if (!(_is >> expect('{'))) {
        cerr << "Glyph: '{' is expected" << endl;
        return _is;
    }

    while (!(_is >> ws >> expect('}'))) {
        std::string key;

        if (!(_is >> reset >> key)) {
            cerr << "Glyph: String keyword is expected" << endl;
            return _is;
        }

        if (key == "p") {
            Polygon polygon;

            if (!(_is >> blank >> polygon)) {
                cerr << "Glyph: Polygon is expected" << endl;
                return _is;
            }

            _obj.polygons.push_back(polygon);
        } else {
            _is.setstate(std::ios_base::failbit);

            cerr << "Glyph: Illegal string keyword" << endl;
            return _is;
        }
    }

    return _is;
}

ostream& operator<< (ostream& _os, const Glyph& _obj) {
    auto& polygons = _obj.polygons;
    auto it = polygons.begin();

    _os << "Glyph ";

    if (it == polygons.end()) {
         _os << "(empty)" << endl;
    } else {
        _os << "{" << endl;

        for (; it != polygons.end(); ++it) {
            _os << '\t' << *it << endl;
        }

        _os << "}" << endl;
    }

    return _os;
}

bool Glyph::IsExceptionalAllPolygon(int x, int y) const {
    /*int index;
    while (index < polygons.size() && !(polygons[index].IsExceptionalPoint(x,y))) {
        index = index + 1;
    }
    return (index == polygons.size());*/
    for (auto& poly : polygons) { 
        if (poly.IsExceptionalPoint(x,y)) { 
            return true;
        } else {
            return false; 
        }
    }
}
