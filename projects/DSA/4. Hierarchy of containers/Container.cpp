#include "Container.h"

Container::Container():data(nullptr), size(0), capacity(0){}
Container::~Container(){delete[]data;}