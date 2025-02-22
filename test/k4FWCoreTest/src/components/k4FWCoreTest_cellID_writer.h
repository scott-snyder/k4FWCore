#ifndef K4FWCORE_K4FWCORETEST_CELLID_WRITER
#define K4FWCORE_K4FWCORETEST_CELLID_WRITER

// GAUDI
#include "GaudiAlg/GaudiAlgorithm.h"

// edm4hep
#include "TTree.h"
#include "k4FWCore/DataHandle.h"

// datamodel
#include "edm4hep/SimTrackerHitCollection.h"

const std::string cellIDtest = "M:3,S-1:3,I:9,J:9,K-1:6";

/** @class k4FWCoreTest_cellID
 *  Lightweight producer for edm data to test cellID
 */
class k4FWCoreTest_cellID_writer : public GaudiAlgorithm {
public:
  explicit k4FWCoreTest_cellID_writer(const std::string&, ISvcLocator*);
  virtual ~k4FWCoreTest_cellID_writer();
  /**  Initialize.
   *   @return status code
   */
  virtual StatusCode initialize() final;
  /**  Execute.
   *   @return status code
   */
  virtual StatusCode execute() final;
  /**  Finalize.
   *   @return status code
   */
  virtual StatusCode finalize() final;

private:
  PodioDataSvc*                   m_podioDataSvc;
  ServiceHandle<IDataProviderSvc> m_eventDataSvc;

  /// Handle for the SimTrackerHits to be written
  DataHandle<edm4hep::SimTrackerHitCollection> m_simTrackerHitWriterHandle{"SimTrackerHits", Gaudi::DataHandle::Writer,
                                                                           this};
};
#endif /* K4FWCORE_K4FWCORETEST_CELLID_WRITER */
