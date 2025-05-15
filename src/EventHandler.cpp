#include "../include/EventHandler.h"

#include "../include/Utils.h"

namespace PVF {

    bool PublicEventSink::Register() {
        if (PVF_API::GetAPI()) {
            static PublicEventSink sink;
            if (const auto actionEventSource = SKSE::GetActionEventSource()) { actionEventSource->AddEventSink<SKSE::ActionEvent>(&sink); }
            return true;
        }
        return false;
    }

    RE::BSEventNotifyControl PublicEventSink::ProcessEvent(const SKSE::ActionEvent* a_event, RE::BSTEventSource<SKSE::ActionEvent>* a_eventSource) {
        if (!a_event || !a_event->actor || !a_event->actor->IsPlayerRef()) return RE::BSEventNotifyControl::kContinue;

        const auto playerActor = a_event->actor->As<RE::Actor>();

        if (a_event->type == SKSE::ActionEvent::Type::kWeaponSwing) {
            Utils::SendSoundEvent("PVFAttackMelee");
        }
        return RE::BSEventNotifyControl::kContinue;
    }

    void DynamicEventSink::Register() {
        static DynamicEventSink sink;
    }
}