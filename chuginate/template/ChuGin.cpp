//-----------------------------------------------------------------------------
// Entaro ChucK Developer!
// This is a chugin boilerplate, generated by chuginate!
//-----------------------------------------------------------------------------
// NOTE by default, chuginate generates a new UGen subclass in this file
//      but it is possible, of course, to create non-UGen classes in a chugin!
// To modify this generated file for a non-UGen class...
//      1. in QUERY->begin_class(), change "UGen" to a different ChucK class
//         (e.g., `QUERY->begin_class(QUERY, "%(CHUGIN_NAME)%", "Object");`)
//      2. remove or commment out the line containing QUERY->add_ugen_func()
//      3. that's it; the rest is no different for UGens/non-UGens
//-----------------------------------------------------------------------------
// NOTE once you have built this into a chugin (%(CHUGIN_NAME)%.chug), here are a few
//      helpful tools for testing / probing / verifying your new chugin!
//
// chuginate also generated a %(CHUGIN_NAME)%-test.ck boilerplate ChucK program
//      to help test your chugin (see %(CHUGIN_NAME)%-test.ck for more instructions)
//
// run `chuck --chugin-probe` to probe what chugins would be loaded, and
//      from where in the chugin search paths
//
// run `chuck -v3 --loop` to see what chugins are actually loaded at runtime,
//      with more info and error reporting than with --chugin-probe
//
// other helpful chugin-related flags include:
//      --chugin:<filename>
//      --chugin-path:(path) / -G(path)
//      --chugin-load:{on/off}
//
// for more information on command-line options:
//      https://chuck.stanford.edu/doc/program/options.html
// for more information on chugins:
//      https://chuck.stanford.edu/extend/
//-----------------------------------------------------------------------------
// happy chucking & chugging!
//-----------------------------------------------------------------------------

// include chugin header
#include "chugin.h"

// general includes
#include <iostream>


// declaration of chugin constructor
CK_DLL_CTOR( %(CHUGIN_LCNAME)%_ctor );
// declaration of chugin desctructor
CK_DLL_DTOR( %(CHUGIN_LCNAME)%_dtor );

// example of getter/setter
CK_DLL_MFUN( %(CHUGIN_LCNAME)%_setParam );
CK_DLL_MFUN( %(CHUGIN_LCNAME)%_getParam );

// for chugins extending UGen, this is mono synthesis function for 1 sample
CK_DLL_TICK( %(CHUGIN_LCNAME)%_tick );

// this is a special offset reserved for chugin internal data
t_CKINT %(CHUGIN_LCNAME)%_data_offset = 0;


//-----------------------------------------------------------------------------
// class definition for internal chugin data
// (NOTE this isn't strictly necessary, but is one example of a recommended approach)
//-----------------------------------------------------------------------------
class %(CHUGIN_NAME)%
{
public:
    // constructor
    %(CHUGIN_NAME)%( t_CKFLOAT fs )
    {
        m_param = 0;
    }

    // for chugins extending UGen
    SAMPLE tick( SAMPLE in )
    {
        // default: this passes whatever input is patched into chugin
        return in;
    }

    // set parameter example
    t_CKFLOAT setParam( t_CKFLOAT p )
    {
        m_param = p;
        return p;
    }

    // get parameter example
    t_CKFLOAT getParam() { return m_param; }
    
private:
    // instance data
    t_CKFLOAT m_param;
};


//-----------------------------------------------------------------------------
// info function: ChucK calls this when loading/probing the chugin
// NOTE: please customize these info fields below; they will be used for
// chugins loading, probing, and package management and documentation
//-----------------------------------------------------------------------------
CK_DLL_INFO( %(CHUGIN_NAME)% )
{
    // the version string of this chugin, e.g., "v1.2.1"
    QUERY->setinfo( QUERY, CHUGIN_INFO_CHUGIN_VERSION, "" );
    // the author(s) of this chugin, e.g., "Alice Baker & Carl Donut"
    QUERY->setinfo( QUERY, CHUGIN_INFO_AUTHORS, "" );
    // text description of this chugin; what is it? what does it do? who is it for?
    QUERY->setinfo( QUERY, CHUGIN_INFO_DESCRIPTION, "" );
    // (optional) URL of the homepage for this chugin
    QUERY->setinfo( QUERY, CHUGIN_INFO_URL, "" );
    // (optional) contact email
    QUERY->setinfo( QUERY, CHUGIN_INFO_EMAIL, "" );
}


//-----------------------------------------------------------------------------
// query function: ChucK calls this when loading the chugin
// modify this function to define this chugin's API and language extensions
//-----------------------------------------------------------------------------
CK_DLL_QUERY( %(CHUGIN_NAME)% )
{
    // generally, don't change this...
    QUERY->setname( QUERY, "%(CHUGIN_NAME)%" );

    // ------------------------------------------------------------------------
    // begin class definition(s); will be compiled, verified,
    // and added to the chuck host type system for use
    // ------------------------------------------------------------------------
    // NOTE to create a non-UGen class, change the second argument
    // to extend a different ChucK class (e.g., "Object")
    QUERY->begin_class( QUERY, "%(CHUGIN_NAME)%", "UGen" );

    // register default constructor
    QUERY->add_ctor( QUERY, %(CHUGIN_LCNAME)%_ctor );
    // NOTE constructors can be overloaded like any other functions,
    // each overloaded constructor begins with `QUERY->add_ctor()`
    // followed by a sequence of `QUERY->add_arg()`

    // register the destructor (probably no need to change)
    QUERY->add_dtor( QUERY, %(CHUGIN_LCNAME)%_dtor );

    // for UGens only: add tick function
    // NOTE a non-UGen class should remove or comment out this next line
    QUERY->add_ugen_func( QUERY, %(CHUGIN_LCNAME)%_tick, NULL, 1, 1 );
    // NOTE: if this is to be a UGen with more than 1 channel,
    // e.g., a multichannel UGen -- will need to use add_ugen_funcf()
    // and declare a tickf function using CK_DLL_TICKF

    // example of adding setter method
    QUERY->add_mfun( QUERY, %(CHUGIN_LCNAME)%_setParam, "float", "param" );
    // example of adding argument to the above method
    QUERY->add_arg( QUERY, "float", "arg" );

    // example of adding getter method
    QUERY->add_mfun( QUERY, %(CHUGIN_LCNAME)%_getParam, "float", "param" );
    
    // this reserves a variable in the ChucK internal class to store 
    // referene to the c++ class we defined above
    %(CHUGIN_LCNAME)%_data_offset = QUERY->add_mvar( QUERY, "int", "@%(CHUGIN_INITIALS)%_data", false );

    // ------------------------------------------------------------------------
    // end the class definition
    // IMPORTANT: this MUST be called to each class definition!
    // ------------------------------------------------------------------------
    QUERY->end_class( QUERY );

    // wasn't that a breeze?
    return TRUE;
}


// implementation for the default constructor
CK_DLL_CTOR( %(CHUGIN_LCNAME)%_ctor )
{
    // get the offset where we'll store our internal c++ class pointer
    OBJ_MEMBER_INT( SELF, %(CHUGIN_LCNAME)%_data_offset ) = 0;
    
    // instantiate our internal c++ class representation
    %(CHUGIN_NAME)% * %(CHUGIN_INITIALS)%_obj = new %(CHUGIN_NAME)%( API->vm->srate(VM) );
    
    // store the pointer in the ChucK object member
    OBJ_MEMBER_INT( SELF, %(CHUGIN_LCNAME)%_data_offset ) = (t_CKINT)%(CHUGIN_INITIALS)%_obj;
}


// implementation for the destructor
CK_DLL_DTOR( %(CHUGIN_LCNAME)%_dtor )
{
    // get our c++ class pointer
    %(CHUGIN_NAME)% * %(CHUGIN_INITIALS)%_obj = (%(CHUGIN_NAME)% *)OBJ_MEMBER_INT( SELF, %(CHUGIN_LCNAME)%_data_offset );
    // clean up (this macro tests for NULL, deletes, and zeros out the variable)
    CK_SAFE_DELETE( %(CHUGIN_INITIALS)%_obj );
    // set the data field to 0
    OBJ_MEMBER_INT( SELF, %(CHUGIN_LCNAME)%_data_offset ) = 0;
}


// implementation for tick function (relevant only for UGens)
CK_DLL_TICK( %(CHUGIN_LCNAME)%_tick )
{
    // get our c++ class pointer
    %(CHUGIN_NAME)% * %(CHUGIN_INITIALS)%_obj = (%(CHUGIN_NAME)% *)OBJ_MEMBER_INT(SELF, %(CHUGIN_LCNAME)%_data_offset);
 
    // invoke our tick function; store in the magical out variable
    if( %(CHUGIN_INITIALS)%_obj ) *out = %(CHUGIN_INITIALS)%_obj->tick( in );

    // yes
    return TRUE;
}


// example implementation for setter
CK_DLL_MFUN( %(CHUGIN_LCNAME)%_setParam )
{
    // get our c++ class pointer
    %(CHUGIN_NAME)% * %(CHUGIN_INITIALS)%_obj = (%(CHUGIN_NAME)% *)OBJ_MEMBER_INT( SELF, %(CHUGIN_LCNAME)%_data_offset );

    // get next argument
    // NOTE argument type must match what is specified above in CK_DLL_QUERY
    // NOTE this advances the ARGS pointer, so save in variable for re-use
    t_CKFLOAT arg1 = GET_NEXT_FLOAT( ARGS );
    
    // call setParam() and set the return value
    RETURN->v_float = %(CHUGIN_INITIALS)%_obj->setParam( arg1 );
}


// example implementation for getter
CK_DLL_MFUN(%(CHUGIN_LCNAME)%_getParam)
{
    // get our c++ class pointer
    %(CHUGIN_NAME)% * %(CHUGIN_INITIALS)%_obj = (%(CHUGIN_NAME)% *)OBJ_MEMBER_INT( SELF, %(CHUGIN_LCNAME)%_data_offset );

    // call getParam() and set the return value
    RETURN->v_float = %(CHUGIN_INITIALS)%_obj->getParam();
}
