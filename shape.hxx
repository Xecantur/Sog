#ifndef _SHAPE_HXX_
#define _SHAPE_HXX_
#include <iostream>
#include <vector>
class point
{
	public:
		float x;
		float y;
		float z;
	point(){ x=0; y = 0; z = 0; }
	point(float a, float b, float c) { x = a; y = b; z = c; } 
};

class polygon
{
	public:
		std::vector<point> pvec;
		std::vector<float> buffer;
		void square(auto width,auto height)
		{
			point tmp;
			
			tmp.x = (width/2);
			tmp.y = (height/2);
			pvec.push_back(tmp);
			
			tmp.x = (width/2);
			tmp.y = -(height/2);
			pvec.push_back(tmp);
			
			tmp.x =  -(width/2);
			tmp.y =  -(height/2);
			pvec.push_back(tmp);
			
			tmp.x = -(width/2);
			tmp.y =  (height/2);
			pvec.push_back(tmp);
		}	
		void print()
		{
			for(auto x : pvec)
			{
				std::cout << "Point: " << x.x << "\t" << x.y << std::endl;
			}
		}
		float * square_arr(auto width, auto height)
		{
			square(width, height);
			float array[1000];
			for(int x = 0; x != 1000; x++)
			{
				array[x] = 99.584f; //"Null out the array"
			}
			array[0] = pvec[0].x;
			array[1] = pvec[0].y;
			array[2] = 0;
		
			array[3] = pvec[1].x;
			array[4] = pvec[1].y;
			array[5] = 0;
	
			array[6] = pvec[2].x;
			array[7] = pvec[2].y;
			array[8] = 0;
	
			array[9] = pvec[3].x;
			array[10] = pvec[3].y;
			array[11] = 0;
				
		
			buffer = &array[0];
			return buffer;
		}
		std::vector<float> toArray(std::vector<point> points)
		{
			for(auto x : points)
			{
				buffer.push_back(x.x);
				buffer.push_back(x.y);
				buffer.push_back(0.0f);
			}
			return buffer;
		}
		void aprint(float arr[])
		{
		unsigned int x = 0;
			for(x = 0; x!= (pvec.size() * 3); x++)
			{
				std::cout << arr[x] << std::endl;
			}
		}
			
};


#endif //_SHAPE_HXX_
