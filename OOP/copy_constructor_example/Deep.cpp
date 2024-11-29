#include "Deep.h"

Deep::Deep(int value) : data(new int(value)) {}

Deep::~Deep() { delete data; }

Deep::Deep(const Deep &sourceObject) : data(new int(*sourceObject.data)) {};

void Deep::setData(int newValue) { *data = newValue; }

int Deep::getData() const { return *data; }
