// PlayFabCPPSDKTest1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "playfab/PlayFabClientDataModels.h"
#include "playfab/PlayFabClientApi.h"
#include "playfab/PlayFabSettings.h"
#include <windows.h>

using namespace PlayFab;
using namespace ClientModels;

bool finished = false;

void OnLoginSuccess(const LoginResult& result, void* customData)
{
	printf("Congratulations, you made your first successful API call!\n");
	finished = true;
}

void OnLoginFail(const PlayFabError& error, void* customData)
{
	printf("Something went wrong with your first API call.\n");
	printf("Here's some debug information:\n");
	printf(error.GenerateErrorReport().c_str());
	printf("\n");
	finished = true;
}

int main()
{
	PlayFabSettings::titleId = ("144");

	LoginWithCustomIDRequest request;
	request.CreateAccount = true;
	request.CustomId = "GettingStartedGuide";

	PlayFabClientAPI::LoginWithCustomID(request, OnLoginSuccess, OnLoginFail);

	while (PlayFabClientAPI::Update() != 0)
		Sleep(1);

	printf("Press enter to exit\n");
	getchar();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
