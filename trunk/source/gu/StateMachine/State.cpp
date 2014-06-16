/************************************************************************/
/*File created on 09.2012 by Cristian Vasile (vasile.cristian@gmail.com)*/
/************************************************************************/


#include "gu/StateMachine/State.h"
#include "gu/StateMachine/StatesStack.h"



namespace gu
{

    
    State::State()
    {
        m_bStateLoading = true;
	    m_pParent = NULL;
    }
    
    State::~State()
    {
	    m_pParent = NULL;
    }
    
    SmartPtr<State> State::GetParent( int level)
    {
	    GU_ASSERT(level >= 0 && level <= STATES_STACK_SIZE);

	    SmartPtr<State> parent = m_pParent;

	    for ( int i = 0 ; i  < level ; i ++ )
	    {
            if (parent->m_pParent.GetPtr())
		    {
			    parent = parent->m_pParent;
		    }
		    else
		    {
			    parent = NULL;
			    break;
		    }
	    }
	    return parent;
    }
    
    int	State::Create()	
    {	
        return 0;	
    }
    
    void State::Release()	
    {

    }
    
    void State::Pause()	
    {

    }
    
    void State::Resume()	
    {

    }
    
    bool State::OnEvent(SmartPtr<EventBase> /*event*/)
    { 
        return false; 
    }
    
    bool State::Load()	
    {	
        return false;	
    }
    
    void State::Update(int /*millisFromLastCall*/)
    {

    }
    
    void State::SetParent(SmartPtr<State> parent)
    { 
        m_pParent = parent;
    }
    
    bool State::isLoading() 
    {
        return m_bStateLoading; 
    }
    
    void State::setLoading( bool loading ) 
    { 
        m_bStateLoading = loading; 
    }
    

} //namesapce gu
