#ifndef OPENFILTER_H
#define OPENFILTER_H
#include <string>

bool isBlocked(const std::string& url);
void applyFilter(const std::string& requestedUrl);

#endif //OPENFILTER_H
