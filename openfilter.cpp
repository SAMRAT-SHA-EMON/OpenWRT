#include <iostream>
#include <string>

bool isBlocked(const std::string& url) {
	// Define the blocked URL
	const std::string blockedUrl = "https://www.freepik.com/";
	//Check if the requested URL matches the blocked URL 
	return (url == blockedUrl);
}
void applyFilter(const std::string& requestedUrl) {
	if (isBlocked(requestedUrl)) {
		std::cout << " Access to " << requestedUrl << "is blocked" << std::endl;
	} else{
		std::cout << " Access to " << requestedUrl << " is allowed." << std::endl;
	}
}
