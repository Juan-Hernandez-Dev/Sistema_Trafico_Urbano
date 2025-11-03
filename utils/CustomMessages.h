#pragma once
#include <string>

void cls();
void Jump();
void Pause(const int milliseconds);
void Header(const std::string& message);
void SubHeader(const std::string& message);
void Msg(const std::string& message);
void MsgLoading(const std::string& message, int cycles = 3, bool clear_after = true);
void MsgModuleLoad(const std::string& module_name, bool* state_variable, const std::string& message = "Loading, please wait", int cycles = 3, bool clear_after = true);
void MsgSuccess(const std::string& message);
void MsgError(const std::string& message);
void MsgWarning(const std::string& message);
void MsgInfo(const std::string& message);
void Prompt(const std::string& message);