#pragma once

#include <string>
#include <vector>
#include "tutorial.h"

class TutorialException
{
private:
	vector<string> errors;

public:
	TutorialException(vector<string> _errors) : errors{ _errors } {}
	vector<string> getErrors() const { return this->errors; }
};;

class TutorialValidator
{
public:
	TutorialValidator() {}
	~TutorialValidator() {}
	void validate(Tutorial);
};