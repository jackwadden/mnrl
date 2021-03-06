// Kevin Angstadt
// angstadt {at} virginia.edu
//
// MNRLHState Object

#ifndef MNRLHSTATE_HPP
#define MNRLHSTATE_HPP

#include <string>
#include <utility>
#include <vector>
#include <map>

#include "MNRLDefs.hpp"
#include "MNRLNode.hpp"
#include "MNRLPort.hpp"
#include "MNRLReportId.hpp"

namespace MNRL {
	class MNRLDefs;
	class MNRLNode;
	class MNRLPort;
	class MNRLHState : public MNRLNode {
		public:
			MNRLHState(
				std::string symbols,
				MNRLDefs::EnableType enable,
				std::string id,
				bool report,
				bool latched,
				std::shared_ptr<MNRLReportId> reportId,
				std::shared_ptr<std::map<std::string,std::string>> attributes
			);
			MNRLHState(
				std::string symbols,
				MNRLDefs::EnableType enable,
				std::string id,
				bool report,
				bool latched,
				int reportId,
				std::shared_ptr<std::map<std::string,std::string>> attributes
			);
			MNRLHState(
				std::string symbols,
				MNRLDefs::EnableType enable,
				std::string id,
				bool report,
				bool latched,
				std::string reportId,
				std::shared_ptr<std::map<std::string,std::string>> attributes
			);
			MNRLHState(
				std::string symbols,
				MNRLDefs::EnableType enable,
				std::string id,
				bool report,
				bool latched,
				std::shared_ptr<std::map<std::string,std::string>> attributes
			);
			virtual ~MNRLHState();

			virtual MNRLDefs::NodeType getNodeType() { return MNRLDefs::NodeType::HSTATE; }

			std::shared_ptr<MNRLReportId> getReportId();
			void setReportId(std::string id);
			void setReportId(int id);
			void setReportId(std::shared_ptr<MNRLReportId> id);

			bool getLatched();
			void setLatched(bool l);

			std::string getSymbolSet();
			void setSymbolSet(std::string set);

		protected:
			std::string symbols;
			bool latched;
			std::shared_ptr<MNRLReportId> reportId;

		private:
			static port_def gen_input() {
				port_def in;
				in.push_back(
					std::shared_ptr<MNRLPort>( new MNRLPort(
							MNRLDefs::H_STATE_INPUT,
							1
						)
					)
				);
				return in;
			}
			static port_def gen_output() {
				port_def outs;
				outs.push_back(
					std::shared_ptr<MNRLPort>( new MNRLPort(
							MNRLDefs::H_STATE_OUTPUT,
							1
						)
					)
				);
				return outs;
			}
	};
}

#endif
