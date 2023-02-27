#include <iostream>
#include <string>
#include <vector>
int partition(vector<Course>& courses, int begin, int end) {

    int low = begin;
    int high = end;
    int i = low - 1;
  
    Course pivot = courses[high];
    string pivotTitle = pivot.code;
  
  	int j = low;
  	while (j <= high) {
      if (courses[j].code < pivotTitle) {
        i++;
        swap(courses[i], courses[j]);
      }
      j++;
    }
  
  	swap(courses[i + 1], courses[high]);
    return i + 1;
}


void quickSort(vector<Course>& courses, int begin, int end) {

    if (begin < end) {
        int mid = partition(courses, begin, end);
        quickSort(courses, begin, mid - 1);
        quickSort(courses, mid + 1, end);
    }  

}

void printCourse(Course course) {
    cout << course.code << ", " << course.name << endl;
    return;
}

int main() {
	vector<Course>courses;
	quickSort(courses, 0, courses.size() - 1);

    for (int i = 0; i < courses.size(); i++)
    {
        printCourse(courses[i]);
    }
}

