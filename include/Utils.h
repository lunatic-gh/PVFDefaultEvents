#pragma once
#include "API.h"

namespace PVF {
    class Utils {
    public:
        static void SendSoundEvent(const char* name) {
            if (const auto api = PVF_API::GetAPI()) api->SendSoundEvent(name);
        }

        static void LogInfo(const char* message) {
            if (const auto api = PVF_API::GetAPI()) api->LogInfo(message);
        }

        static void LogWarn(const char* message) {
            if (const auto api = PVF_API::GetAPI()) api->LogWarn(message);
        }

        static void LogError(const char* message) {
            if (const auto api = PVF_API::GetAPI()) api->LogError(message);
        }

        static void LogCritical(const char* message) {
            if (const auto api = PVF_API::GetAPI()) api->LogCritical(message);
        }

        static void LogDebug(const char* message) {
            if (const auto api = PVF_API::GetAPI()) api->LogDebug(message);
        }

        static void RegisterCondition(const char* eventName, const char* conditionName, const ConditionFunction& conditionFunction) {
            if (const auto api = PVF_API::GetAPI()) api->RegisterCondition(eventName, conditionName, conditionFunction);
        }

        static void RegisterGlobalCondition(const char* conditionName, const ConditionFunction& conditionFunction) {
            if (const auto api = PVF_API::GetAPI()) api->RegisterGlobalCondition(conditionName, conditionFunction);
        }
    };
}
