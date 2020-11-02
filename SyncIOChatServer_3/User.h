#pragma once
#include <string>

namespace ChatServerLib
{
	class User
	{
	public:
		enum class DOMAIN_STATE {
			NONE = 0,
			LOGIN = 1,
			LOBBY = 2,
			ROOM = 3,
		};

	public:
		User() {}
		virtual ~User() {}

		void Init(const short index)
		{
			m_Index = index;
		}

		void Clear()
		{
			m_SessionIndex = 0;
			m_ID = "";
			m_CurDomainState = DOMAIN_STATE::NONE;
			m_RoomIndex = -1;
			m_Black = false;
			m_White = false;
		}

		void Set(const int sessionIndex, const char* pszID)
		{
			m_CurDomainState = DOMAIN_STATE::LOGIN;
			m_SessionIndex = sessionIndex;
			m_ID = pszID;
		}

		short GetIndex() { return m_Index; }

		int GetSessioIndex() { return m_SessionIndex; }

		std::string& GetID() { return m_ID; }

		short GetRoomIndex() { return m_RoomIndex; }

		void EnterRoom( const short roomIndex)
		{
			m_RoomIndex = roomIndex;
			m_CurDomainState = DOMAIN_STATE::ROOM;
		}

		void LeaveRoom()
		{
			m_CurDomainState = DOMAIN_STATE::LOGIN;
		}


		bool IsCurDomainInLogIn() {
			return m_CurDomainState == DOMAIN_STATE::LOGIN ? true : false;
		}

		bool IsCurDomainInRoom() {
			return m_CurDomainState == DOMAIN_STATE::ROOM ? true : false;
		}

		void SetBlack() { m_Black = true; };

	protected:
		short m_Index = -1;

		int m_SessionIndex = -1;

		std::string m_ID;

		DOMAIN_STATE m_CurDomainState = DOMAIN_STATE::NONE;

		short m_RoomIndex = -1;

		bool m_Black = false;
		bool m_White = false;
	};
}