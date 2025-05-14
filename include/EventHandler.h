#pragma once
#pragma warning(disable : 4100) // "unreferenced formal parameter"

#include <RE/B/BSTEvent.h>
#include <SKSE/Events.h>

namespace PVF {
    class PublicEventSink final : RE::BSTEventSink<SKSE::ActionEvent> {
    public:
        static bool Register();

        RE::BSEventNotifyControl ProcessEvent(const SKSE::ActionEvent* a_event, RE::BSTEventSource<SKSE::ActionEvent>* a_eventSource) override;
    };

    class DynamicEventSink final {
    public:
        static void Register();
    };
}
