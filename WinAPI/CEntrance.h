#pragma once
#include "CGameObject.h"
#include "framework.h"
class CEntrance :
    public CGameObject
{
public:
    CEntrance();
    virtual ~CEntrance();
    GroupScene GetNextScene();
    void SetNextScene(GroupScene Scene);

private:
    GroupScene pNextScene;
    void Init() override;
    void Update() override;
    void Render() override;
    void Release()  override;
    void OnCollisionEnter(CCollider* pOtherCollider);
    //void OnCollisionEnter(CCollider* pOtherCollider)
    //void OnCollisionEnter(CCollider* pOtherCollider)
};

