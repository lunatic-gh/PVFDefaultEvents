// ReSharper disable CppParameterMayBeConstPtrOrRef

#include "../include/EventHandler.h"
#include "../include/Utils.h"

SKSEPluginLoad(const SKSE::LoadInterface* skse) {
    SKSE::Init(skse);
    SKSE::GetMessagingInterface()->RegisterListener([](SKSE::MessagingInterface::Message *message) {
        switch (message->type) {
            case SKSE::MessagingInterface::kDataLoaded: {
                PVF::Utils::LogInfo("Initializing Default-Events");
                PVF::PublicEventSink::Register();
                PVF::Utils::LogInfo("Initializing Default-Events - Done");
                break;
            default:
                break;
            }
        }
    });
    return true;
}
