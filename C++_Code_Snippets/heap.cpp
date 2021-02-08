// Priority Queue for Integers
priority_queue <int> pq;

// Insert value
pq.push(val);

// Check if empty
if(pq.empty())
  cout << "Empty Heap" ;

// Get top element
int max_val = pq.top();

// Remove top element
pq.pop();

// Creates a min heap
// https://www.geeksforgeeks.org/implement-min-heap-using-stl/
priority_queue <int, vector<int>, greater<int> > pq;

// Creates a min heap of an user-defined class i.e. points (order by x coordinate)
class Point{
   int x;
   int y;
public:
   Point(int _x, int _y){
      x = _x;
      y = _y;
   }
   int getX() const { return x; }
   int getY() const { return y; }
};
struct comparator{
	bool operator() (const Point& p1, const Point& p2){
		return p1.getX() > p2.getX();
	}
};
priority_queue <Point, vector<Point>, comparator > pq;

// Creates a min heap of an user-defined class i.e. points (order by x coordinate)
class Point{
   int x;
   int y;
public:
   Point(int _x, int _y){
      x = _x;
      y = _y;
   }
   int getX() const { return x; }
   int getY() const { return y; }
};
class myComparator{
public:
	int operator() (const Point& p1, const Point& p2){
		return p1.getX() > p2.getX();
	}
};
priority_queue <Point, vector<Point>, myComparator > pq;


