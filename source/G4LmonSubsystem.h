// Tell emacs that this is a C++ source
//  -*- C++ -*-.
#ifndef G4LMONSUBSYSTEM_H
#define G4LMONSUBSYSTEM_H

#include <g4main/PHG4Subsystem.h>

#include <string>

class PHCompositeNode;
class PHG4Detector;
class G4LmonDetector;
class PHG4SteppingAction;

/**
   * \brief example Fun4All module
   *
   * The detector is constructed and registered via G4LmonDetector
   *
   *
   * \see G4LmonDetector
   * \see G4LmonSubsystem
   *
   */
class G4LmonSubsystem : public PHG4Subsystem
{
 public:
  //! constructor
  G4LmonSubsystem(const std::string& name = "Example01");

  //! destructor
  virtual ~G4LmonSubsystem(){}

  /*!
  creates the m_Detector object and place it on the node tree, under "DETECTORS" node (or whatever)
  reates the stepping action and place it on the node tree, under "ACTIONS" node
  creates relevant hit nodes that will be populated by the stepping action and stored in the output DST
  */
  virtual int Init(PHCompositeNode*);

  //! event processing
  /*!
  get all relevant nodes from top nodes (namely hit list)
  and pass that to the stepping action
  */
  virtual int process_event(PHCompositeNode*);

  //! accessors (reimplemented)
  virtual PHG4Detector* GetDetector() const;

  virtual PHG4SteppingAction* GetSteppingAction() const {return  m_SteppingAction;}
  //! Print info (from SubsysReco)
  virtual void Print(const std::string& what = "ALL") const;

 private:

  //! detector geometry
  /*! defives from PHG4Detector */
  G4LmonDetector* m_Detector;

  //! particle tracking "stepping" action
  /*! derives from PHG4SteppingActions */
  PHG4SteppingAction* m_SteppingAction;
};

#endif  // G4LMONSUBSYSTEM_H
