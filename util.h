#pragma once

/*
Util.h
header-only utility function file
*/

//From https://www.tutorialspoint.com/cplusplus-equivalent-of-instanceof
template<typename Base, typename T>
inline bool instanceOf(const T*) {
	return is_base_of<Base, T>::value;
}


struct vector2 {
    int x;
    int y;
};