#include "tutorial_validator.h"

void TutorialValidator::validate(Tutorial tutorial)
{
	vector<string> errors;
	if (tutorial.getTitle() == "")
		errors.push_back("The title is empty");

	if (tutorial.getPresenter() == "")
		errors.push_back("The presenter is empty");

	if (tutorial.getDuration() <= 0)
		errors.push_back("The duration is not valid");

	if (tutorial.getLikes() <= 0)
		errors.push_back("The number of likes is not valid");

	if (tutorial.getLink() == "")
		errors.push_back("The link is empty");

	size_t https = tutorial.getLink().find("https:");
	if (https != 0)
		errors.push_back("The link is not valid"); 

	if (errors.size() > 0)
		throw TutorialException(errors);
}
