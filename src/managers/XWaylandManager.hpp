#pragma once

#include "../defines.hpp"
#include <optional>

class CWindow; // because clangd

class CHyprXWaylandManager {
  public:
    CHyprXWaylandManager();
    ~CHyprXWaylandManager();

    wlr_xwayland* m_sWLRXWayland = nullptr;

    wlr_surface*  getWindowSurface(CWindow*);
    void          activateSurface(wlr_surface*, bool);
    void          activateWindow(CWindow*, bool);
    void          getGeometryForWindow(CWindow*, CBox*);
    std::string   getTitle(CWindow*);
    std::string   getAppIDClass(CWindow*);
    void          sendCloseWindow(CWindow*);
    void          setWindowSize(CWindow*, Vector2D, bool force = false);
    void          setWindowStyleTiled(CWindow*, uint32_t);
    void          setWindowFullscreen(CWindow*, bool);
    wlr_surface*  surfaceAt(CWindow*, const Vector2D&, Vector2D&);
    bool          shouldBeFloated(CWindow*, bool pending = false);
    void          moveXWaylandWindow(CWindow*, const Vector2D&);
    void          checkBorders(CWindow*);
    Vector2D      getMaxSizeForWindow(CWindow*);
    Vector2D      xwaylandToWaylandCoords(const Vector2D&);
};

inline std::unique_ptr<CHyprXWaylandManager> g_pXWaylandManager;