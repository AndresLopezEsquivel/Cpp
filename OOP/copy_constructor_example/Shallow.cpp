#include "Shallow.h"

Shallow::Shallow(int value) : data(new int(value)) {}

Shallow::~Shallow() { delete data; }

void Shallow::setData(int newValue) { *data = newValue; }

int Shallow::getData() const { return *data; }
