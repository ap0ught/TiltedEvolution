#pragma once

#include <Events/EventDispatcher.h>
#include <Games/Events.h>

struct World;

struct ConnectedEvent;
struct GameService;

struct PreUpdateEvent;
struct ReferenceSpawnedEvent;

struct TESObjectREFR;
struct TESWorldSpace;

struct DiscoveryService final
    : BSTEventSink<TESLoadGameEvent>
{
    DiscoveryService(World& aWorld, entt::dispatcher& aDispatcher) noexcept;
    ~DiscoveryService() noexcept = default;

    TP_NOCOPYMOVE(DiscoveryService);

protected:

    void VisitCell(bool aForceTrigger = false) noexcept;
    void DetectGridCellChange(TESWorldSpace* aWorldSpace, bool aNewGridCell) noexcept;
    void VisitForms() noexcept;

    void OnUpdate(const PreUpdateEvent& acPreUpdateEvent) noexcept;

    void OnConnected(const ConnectedEvent& acEvent) noexcept;

    BSTEventResult OnEvent(const TESLoadGameEvent*, const EventDispatcher<TESLoadGameEvent>*) override;

private:

    World& m_world;
    entt::dispatcher& m_dispatcher;

    Set<uint32_t> m_forms;
    int32_t m_centerGridX = 0xFFFF;
    int32_t m_centerGridY = 0xFFFF;
    int32_t m_currentGridX = 0xFFFF;
    int32_t m_currentGridY = 0xFFFF;
    uint32_t m_worldSpaceId = 0;
    uint32_t m_interiorCellId = 0;
    struct TESForm *m_pLocation = nullptr;

    bool m_loadGame = false;

    entt::scoped_connection m_preUpdateConnection;
    entt::scoped_connection m_connectedConnection;
};
