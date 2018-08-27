/* ============================================================================
 *  tubex-lib - VibesFigure_Map class
 * ============================================================================
 *  Copyright : Copyright 2017 Simon Rohou
 *  License   : This program is distributed under the terms of
 *              the GNU Lesser General Public License (LGPL).
 *
 *  Author(s) : Simon Rohou
 *  Bug fixes : -
 *  Created   : 2015
 * ---------------------------------------------------------------------------- */

#ifndef __TUBEX_VIBESFIGUREMAP_H__
#define __TUBEX_VIBESFIGUREMAP_H__

#include <map>
#include <vector>

#include "tubex_VibesFigure.h"
#include "tubex_TubeVector.h"
#include "tubex_TrajectoryVector.h"
#include "tubex_Beacon.h"

namespace tubex
{
  #define TRAJMAP_NB_DISPLAYED_POINTS   10000
  #define MAP_SLICES_NUMBER_TO_DISPLAY  10000

  // HTML color codes:
  #define DEFAULT_BEACON_COLOR      "#FF5D00[white]"
  #define DEFAULT_TRAJMAP_COLOR     "#276279"
  #define DEFAULT_MAPBCKGRND_COLOR  "#d2d2d2[#d2d2d2]"
  #define DEFAULT_OBS_COLOR         "gray"

  class VibesFigure_Map : public VibesFigure
  {
    public:

      VibesFigure_Map(const std::string& fig_name);
      ~VibesFigure_Map();
      
      void add_tubevector(const TubeVector *tube, const std::string& name, int index_x, int index_y);
      void set_tubevector_name(const TubeVector *tube, const std::string& name);
      void remove_tubevector(const TubeVector *tube);

      void add_trajectoryvector(const TrajectoryVector *traj, const std::string& name, int index_x, int index_y, int index_heading = -1, const std::string& color = DEFAULT_TRAJMAP_COLOR);
      void set_trajectoryvector_name(const TrajectoryVector *traj, const std::string& name);
      void set_trajectoryvector_color(const TrajectoryVector *traj, const std::string& color);
      void remove_trajectoryvector(const TrajectoryVector *traj);

      void add_beacon(const Beacon& beacon, const std::string& color = DEFAULT_BEACON_COLOR);
      void add_beacons(const std::vector<Beacon>& v_beacons, const std::string& color = DEFAULT_BEACON_COLOR);

      void add_observation(const ibex::IntervalVector& obs, const TrajectoryVector *traj, const std::string& color = DEFAULT_OBS_COLOR);
      void add_observations(const std::vector<ibex::IntervalVector>& v_obs, const TrajectoryVector *traj, const std::string& color = DEFAULT_OBS_COLOR);
  
      virtual void show();

    protected:

      const ibex::IntervalVector draw_tube(const TubeVector *tube_ref);
      const ibex::IntervalVector draw_tube_background(const TubeVector *tube_ref);
      const ibex::IntervalVector draw_trajectory(const TrajectoryVector *traj, float points_size = 0.);
      void draw_tube_slices(const TubeVector *tube);
      const std::string shaded_slice_color(float r) const;
      void draw_vehicle(double t, const TrajectoryVector *traj, const vibes::Params& params);
      void draw_beacon(const Beacon& beacon, const std::string& color, const vibes::Params& params);
      void draw_observation(const ibex::IntervalVector& obs, const TrajectoryVector *traj, const std::string& color, const vibes::Params& params);

    protected:

      struct FigMapTubeParams
      {
        const TubeVector *tube_copy = NULL; // to display previous values in background
        std::string name;
        int index_x, index_y;
      };

      struct FigMapTrajParams
      {
        std::string color;
        std::string name;
        int index_x, index_y, index_heading = -1; // -1: not defined
      };

      std::map<const TubeVector*,FigMapTubeParams> m_map_tubes;
      std::map<const TrajectoryVector*,FigMapTrajParams> m_map_trajs;
  };
}

#endif