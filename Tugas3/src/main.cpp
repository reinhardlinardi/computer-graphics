#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "lib/framebuffer.h"
#include "lib/line.h"
#include "font.h"

using namespace std;

int main (int argc, char** argv)
{
	if (argc != 3) {
    cerr << "Usage: " << argv[0] << " FONT_PATH GLYPH" << endl;
    return 1;
  }

  const char* font_path = argv[1];
  const char* glyph = argv[2];

  // Load font.

  ifstream in;
	in.open(font_path);

  if (!in.is_open()) {
    cerr << argv[0] << ": Unable to load file: " << font_path << endl;
    return 1;
  }

  Font font;
  in >> font;

  if (!in) {
    cerr << argv[0] << ": Unable to parse file" << endl;
    return 1;
  }

  // Print font.

  Framebuffer buf;
  for (int i=0;i<strlen(glyph);i++) {
  	font[glyph[i]].Draw(buf, i*16, 0, 0xFFFFFF, 0x0000FF, buf.BUF_MAIN);
  }

  // Sleep.
  sleep(3);
  /*Raster raster (0,0,400,400);
  raster.Coloring(buf,0xffffff,0x534200,buf.BUF_MAIN);*/

/*	 int x1 = 55;
	 int y1 = 147;
	 int x2 = 250;
	 int y2 = 80;
	// int phase = 0;

	/* Line line(x1, y1, x2, y2);
	 Line line2(250,80,278,369);
	 Line line3(278,369,387,216);
	 Line line4(387,216,64,292);
	 Line line5(64,292,55,147);
	Raster raster(0,55,400,400);
	int t = 1;
	
	/*for(int t=1;t<=5;t++)
	{
		int cnt = 800;

		while(cnt--)
		{*/
			 /*line.Draw(buf, 0xFFFFFF, t, buf.BUF_MAIN);
			 line2.Draw(buf, 0xFFFFFF, t, buf.BUF_MAIN);
			 line3.Draw(buf, 0xFFFFFF, t, buf.BUF_MAIN);
			 line4.Draw(buf, 0xFFFFFF, t, buf.BUF_MAIN);
			 line5.Draw(buf, 0xFFFFFF, t, buf.BUF_MAIN);
			// if (buf.isColor(10,10,0x534200,buf.BUF_MAIN)) {
			// 	line.Draw(buf, 0x534200, t, buf.BUF_MAIN);
			// 	line2.Draw(buf, 0x534200, t, buf.BUF_MAIN);
			// 	line3.Draw(buf, 0x534200, t, buf.BUF_MAIN);
			// }
			 sleep(3);
			 raster.Coloring(buf, 0xFFFFFF,0x534200,buf.BUF_MAIN);


			/*line.Draw(buf, 0x5342f4, t, buf.BUF_BACK);
			line2.Draw(buf, 0x5342f4, t, buf.BUF_BACK);
			
			/*if (phase == 0)
			{
				line.x1 += 1;
				if (line.x1 >= 200) phase = 1;
			}
			else if (phase == 1)
			{
				line.y1 += 1;
				if (line.y1 >= 200) phase = 2;
			}
			else if (phase == 2)
			{
				line.x1 -= 1;
				if (line.x1 <= 0) phase = 3;
			}
			else if (phase == 3)
			{
				line.y1 -= 1;
				if (line.y1 <= 0) phase = 0;
			}
			if (buf.isColor(100,100,0x5342f4,buf.BUF_BACK)) {
				//printf("AAAAAAAAAAAAAAAAAAAAAAAAa\n");
				line2.x1 = line2.x1 + 1;
				//line2.Draw(buf, 0x5342f4, t, buf.BUF_BACK);
			}
			buf.Flush();
			usleep(10000);*/
		/*}

		sleep(2);
	}*/

	return 0;
}