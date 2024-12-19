#include "openfilter.h"
int main(){
	// Test with the blocked URL
	applyFilter("https://www.freepik.com/");
	// Test with an allowed URL
	applyFilter("https://www.facebook.com/");
	return 0;
}
