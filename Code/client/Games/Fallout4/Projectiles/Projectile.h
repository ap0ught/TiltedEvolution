#pragma once

#include <Games/Misc/MagicSystem.h>

struct BGSProjectile;
struct TESObjectREFR;
struct CombatController;
struct TESForm;
struct TESAmmo;
struct TESObjectCELL;
struct MagicItem;
struct AlchemyItem;

struct ProjectileLaunchData
{
    NiPoint3 Origin;
    NiPoint3 ContactNormal;
    TESForm* pProjectileBase; // is actually BGSProjectile*
    TESObjectREFR* pShooter;
    CombatController* pShooterCombatController;
    //BGSObjectInstanceT<TESObjectWEAP> FromWeapon; // length: 0x10
    TESForm* pFromWeapon;
    void* pFromWeaponData;
    TESAmmo *pFromAmmo;
    //BGSEquipIndex EquipIndex;
    uint32_t EquipIndex;
    float fZAngle;
    float fXAngle;
    float fYAngle;
    TESObjectREFR *pHomingTarget;
    TESObjectCELL *pParentCell;
    MagicItem *pSpell;
    MagicSystem::CastingSource eCastingSource;
    AlchemyItem *pPoison;
    int iArea;
    float fPower;
    float fScale;
    float fConeOfFireRadiusMult;
    int32_t eTargetLimb;
    bool bAlwaysHit;
    bool bNoDamageOutsideCombat;
    bool bAutoAim;
    bool bUseOrigin;
    bool bDeferInitialization;
    bool bTracer;
    bool bForceConeOfFire;
    bool bIntentionalMiss;
    bool bAllow3D;
    bool bPenetrates;
    bool bIgnoreNearCollisions;
};

struct Projectile
{
    static void* Launch(void* apResult, ProjectileLaunchData& arData);
};

