// Copyright (c) 2005-2017 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "drivesschema.h"

// Properties_t
// 

const Properties_t::ActionOptional& Properties_t::
action () const
{
  return this->action_;
}

Properties_t::ActionOptional& Properties_t::
action ()
{
  return this->action_;
}

void Properties_t::
action (const ActionType& x)
{
  this->action_.set (x);
}

void Properties_t::
action (const ActionOptional& x)
{
  this->action_ = x;
}

void Properties_t::
action (::std::unique_ptr< ActionType > x)
{
  this->action_.set (std::move (x));
}

const Properties_t::ThisDriveOptional& Properties_t::
thisDrive () const
{
  return this->thisDrive_;
}

Properties_t::ThisDriveOptional& Properties_t::
thisDrive ()
{
  return this->thisDrive_;
}

void Properties_t::
thisDrive (const ThisDriveType& x)
{
  this->thisDrive_.set (x);
}

void Properties_t::
thisDrive (const ThisDriveOptional& x)
{
  this->thisDrive_ = x;
}

void Properties_t::
thisDrive (::std::unique_ptr< ThisDriveType > x)
{
  this->thisDrive_.set (std::move (x));
}

const Properties_t::AllDrivesOptional& Properties_t::
allDrives () const
{
  return this->allDrives_;
}

Properties_t::AllDrivesOptional& Properties_t::
allDrives ()
{
  return this->allDrives_;
}

void Properties_t::
allDrives (const AllDrivesType& x)
{
  this->allDrives_.set (x);
}

void Properties_t::
allDrives (const AllDrivesOptional& x)
{
  this->allDrives_ = x;
}

void Properties_t::
allDrives (::std::unique_ptr< AllDrivesType > x)
{
  this->allDrives_.set (std::move (x));
}

const Properties_t::UserNameOptional& Properties_t::
userName () const
{
  return this->userName_;
}

Properties_t::UserNameOptional& Properties_t::
userName ()
{
  return this->userName_;
}

void Properties_t::
userName (const UserNameType& x)
{
  this->userName_.set (x);
}

void Properties_t::
userName (const UserNameOptional& x)
{
  this->userName_ = x;
}

void Properties_t::
userName (::std::unique_ptr< UserNameType > x)
{
  this->userName_.set (std::move (x));
}

const Properties_t::CpasswordOptional& Properties_t::
cpassword () const
{
  return this->cpassword_;
}

Properties_t::CpasswordOptional& Properties_t::
cpassword ()
{
  return this->cpassword_;
}

void Properties_t::
cpassword (const CpasswordType& x)
{
  this->cpassword_.set (x);
}

void Properties_t::
cpassword (const CpasswordOptional& x)
{
  this->cpassword_ = x;
}

void Properties_t::
cpassword (::std::unique_ptr< CpasswordType > x)
{
  this->cpassword_.set (std::move (x));
}

const Properties_t::PathType& Properties_t::
path () const
{
  return this->path_.get ();
}

Properties_t::PathType& Properties_t::
path ()
{
  return this->path_.get ();
}

void Properties_t::
path (const PathType& x)
{
  this->path_.set (x);
}

void Properties_t::
path (::std::unique_ptr< PathType > x)
{
  this->path_.set (std::move (x));
}

const Properties_t::LabelOptional& Properties_t::
label () const
{
  return this->label_;
}

Properties_t::LabelOptional& Properties_t::
label ()
{
  return this->label_;
}

void Properties_t::
label (const LabelType& x)
{
  this->label_.set (x);
}

void Properties_t::
label (const LabelOptional& x)
{
  this->label_ = x;
}

void Properties_t::
label (::std::unique_ptr< LabelType > x)
{
  this->label_.set (std::move (x));
}

const Properties_t::PersistentType& Properties_t::
persistent () const
{
  return this->persistent_.get ();
}

Properties_t::PersistentType& Properties_t::
persistent ()
{
  return this->persistent_.get ();
}

void Properties_t::
persistent (const PersistentType& x)
{
  this->persistent_.set (x);
}

const Properties_t::UseLetterType& Properties_t::
useLetter () const
{
  return this->useLetter_.get ();
}

Properties_t::UseLetterType& Properties_t::
useLetter ()
{
  return this->useLetter_.get ();
}

void Properties_t::
useLetter (const UseLetterType& x)
{
  this->useLetter_.set (x);
}

const Properties_t::LetterType& Properties_t::
letter () const
{
  return this->letter_.get ();
}

Properties_t::LetterType& Properties_t::
letter ()
{
  return this->letter_.get ();
}

void Properties_t::
letter (const LetterType& x)
{
  this->letter_.set (x);
}

void Properties_t::
letter (::std::unique_ptr< LetterType > x)
{
  this->letter_.set (std::move (x));
}

const Properties_t::DisabledOptional& Properties_t::
disabled () const
{
  return this->disabled_;
}

Properties_t::DisabledOptional& Properties_t::
disabled ()
{
  return this->disabled_;
}

void Properties_t::
disabled (const DisabledType& x)
{
  this->disabled_.set (x);
}

void Properties_t::
disabled (const DisabledOptional& x)
{
  this->disabled_ = x;
}


// Drive_t
// 

const Drive_t::PropertiesSequence& Drive_t::
Properties () const
{
  return this->Properties_;
}

Drive_t::PropertiesSequence& Drive_t::
Properties ()
{
  return this->Properties_;
}

void Drive_t::
Properties (const PropertiesSequence& s)
{
  this->Properties_ = s;
}

const Drive_t::ClsidType& Drive_t::
clsid () const
{
  return this->clsid_.get ();
}

Drive_t::ClsidType& Drive_t::
clsid ()
{
  return this->clsid_.get ();
}

void Drive_t::
clsid (const ClsidType& x)
{
  this->clsid_.set (x);
}

void Drive_t::
clsid (::std::unique_ptr< ClsidType > x)
{
  this->clsid_.set (std::move (x));
}

const Drive_t::NameType& Drive_t::
name () const
{
  return this->name_.get ();
}

Drive_t::NameType& Drive_t::
name ()
{
  return this->name_.get ();
}

void Drive_t::
name (const NameType& x)
{
  this->name_.set (x);
}

void Drive_t::
name (::std::unique_ptr< NameType > x)
{
  this->name_.set (std::move (x));
}

const Drive_t::ImageOptional& Drive_t::
image () const
{
  return this->image_;
}

Drive_t::ImageOptional& Drive_t::
image ()
{
  return this->image_;
}

void Drive_t::
image (const ImageType& x)
{
  this->image_.set (x);
}

void Drive_t::
image (const ImageOptional& x)
{
  this->image_ = x;
}

const Drive_t::ChangedOptional& Drive_t::
changed () const
{
  return this->changed_;
}

Drive_t::ChangedOptional& Drive_t::
changed ()
{
  return this->changed_;
}

void Drive_t::
changed (const ChangedType& x)
{
  this->changed_.set (x);
}

void Drive_t::
changed (const ChangedOptional& x)
{
  this->changed_ = x;
}

void Drive_t::
changed (::std::unique_ptr< ChangedType > x)
{
  this->changed_.set (std::move (x));
}

const Drive_t::UidType& Drive_t::
uid () const
{
  return this->uid_.get ();
}

Drive_t::UidType& Drive_t::
uid ()
{
  return this->uid_.get ();
}

void Drive_t::
uid (const UidType& x)
{
  this->uid_.set (x);
}

void Drive_t::
uid (::std::unique_ptr< UidType > x)
{
  this->uid_.set (std::move (x));
}

const Drive_t::DescOptional& Drive_t::
desc () const
{
  return this->desc_;
}

Drive_t::DescOptional& Drive_t::
desc ()
{
  return this->desc_;
}

void Drive_t::
desc (const DescType& x)
{
  this->desc_.set (x);
}

void Drive_t::
desc (const DescOptional& x)
{
  this->desc_ = x;
}

void Drive_t::
desc (::std::unique_ptr< DescType > x)
{
  this->desc_.set (std::move (x));
}

const Drive_t::BypassErrorsOptional& Drive_t::
bypassErrors () const
{
  return this->bypassErrors_;
}

Drive_t::BypassErrorsOptional& Drive_t::
bypassErrors ()
{
  return this->bypassErrors_;
}

void Drive_t::
bypassErrors (const BypassErrorsType& x)
{
  this->bypassErrors_.set (x);
}

void Drive_t::
bypassErrors (const BypassErrorsOptional& x)
{
  this->bypassErrors_ = x;
}

const Drive_t::UserContextOptional& Drive_t::
userContext () const
{
  return this->userContext_;
}

Drive_t::UserContextOptional& Drive_t::
userContext ()
{
  return this->userContext_;
}

void Drive_t::
userContext (const UserContextType& x)
{
  this->userContext_.set (x);
}

void Drive_t::
userContext (const UserContextOptional& x)
{
  this->userContext_ = x;
}

const Drive_t::RemovePolicyOptional& Drive_t::
removePolicy () const
{
  return this->removePolicy_;
}

Drive_t::RemovePolicyOptional& Drive_t::
removePolicy ()
{
  return this->removePolicy_;
}

void Drive_t::
removePolicy (const RemovePolicyType& x)
{
  this->removePolicy_.set (x);
}

void Drive_t::
removePolicy (const RemovePolicyOptional& x)
{
  this->removePolicy_ = x;
}

const Drive_t::StatusOptional& Drive_t::
status () const
{
  return this->status_;
}

Drive_t::StatusOptional& Drive_t::
status ()
{
  return this->status_;
}

void Drive_t::
status (const StatusType& x)
{
  this->status_.set (x);
}

void Drive_t::
status (const StatusOptional& x)
{
  this->status_ = x;
}

void Drive_t::
status (::std::unique_ptr< StatusType > x)
{
  this->status_.set (std::move (x));
}


// Drives
// 

const Drives::DriveSequence& Drives::
Drive () const
{
  return this->Drive_;
}

Drives::DriveSequence& Drives::
Drive ()
{
  return this->Drive_;
}

void Drives::
Drive (const DriveSequence& s)
{
  this->Drive_ = s;
}

const Drives::ClsidType& Drives::
clsid () const
{
  return this->clsid_.get ();
}

Drives::ClsidType& Drives::
clsid ()
{
  return this->clsid_.get ();
}

void Drives::
clsid (const ClsidType& x)
{
  this->clsid_.set (x);
}

void Drives::
clsid (::std::unique_ptr< ClsidType > x)
{
  this->clsid_.set (std::move (x));
}

const Drives::DisabledOptional& Drives::
disabled () const
{
  return this->disabled_;
}

Drives::DisabledOptional& Drives::
disabled ()
{
  return this->disabled_;
}

void Drives::
disabled (const DisabledType& x)
{
  this->disabled_.set (x);
}

void Drives::
disabled (const DisabledOptional& x)
{
  this->disabled_ = x;
}


#include <xsd/cxx/xml/dom/wildcard-source.hxx>

#include <xsd/cxx/xml/dom/parsing-source.hxx>

#include <xsd/cxx/tree/type-factory-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::type_factory_plate< 0, char >
  type_factory_plate_init;
}

// Properties_t
//

Properties_t::
Properties_t (const PathType& path,
              const PersistentType& persistent,
              const UseLetterType& useLetter,
              const LetterType& letter)
: ::xml_schema::Type (),
  action_ (this),
  thisDrive_ (this),
  allDrives_ (this),
  userName_ (this),
  cpassword_ (this),
  path_ (path, this),
  label_ (this),
  persistent_ (persistent, this),
  useLetter_ (useLetter, this),
  letter_ (letter, this),
  disabled_ (this)
{
}

Properties_t::
Properties_t (const Properties_t& x,
              ::xml_schema::Flags f,
              ::xml_schema::Container* c)
: ::xml_schema::Type (x, f, c),
  action_ (x.action_, f, this),
  thisDrive_ (x.thisDrive_, f, this),
  allDrives_ (x.allDrives_, f, this),
  userName_ (x.userName_, f, this),
  cpassword_ (x.cpassword_, f, this),
  path_ (x.path_, f, this),
  label_ (x.label_, f, this),
  persistent_ (x.persistent_, f, this),
  useLetter_ (x.useLetter_, f, this),
  letter_ (x.letter_, f, this),
  disabled_ (x.disabled_, f, this)
{
}

Properties_t::
Properties_t (const ::xercesc::DOMElement& e,
              ::xml_schema::Flags f,
              ::xml_schema::Container* c)
: ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
  action_ (this),
  thisDrive_ (this),
  allDrives_ (this),
  userName_ (this),
  cpassword_ (this),
  path_ (this),
  label_ (this),
  persistent_ (this),
  useLetter_ (this),
  letter_ (this),
  disabled_ (this)
{
  if ((f & ::xml_schema::Flags::base) == 0)
  {
    ::xsd::cxx::xml::dom::parser< char > p (e, false, false, true);
    this->parse (p, f);
  }
}

void Properties_t::
parse (::xsd::cxx::xml::dom::parser< char >& p,
       ::xml_schema::Flags f)
{
  while (p.more_attributes ())
  {
    const ::xercesc::DOMAttr& i (p.next_attribute ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    if (n.name () == "action" && n.namespace_ ().empty ())
    {
      this->action_.set (ActionTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "thisDrive" && n.namespace_ ().empty ())
    {
      this->thisDrive_.set (ThisDriveTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "allDrives" && n.namespace_ ().empty ())
    {
      this->allDrives_.set (AllDrivesTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "userName" && n.namespace_ ().empty ())
    {
      this->userName_.set (UserNameTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "cpassword" && n.namespace_ ().empty ())
    {
      this->cpassword_.set (CpasswordTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "path" && n.namespace_ ().empty ())
    {
      this->path_.set (PathTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "label" && n.namespace_ ().empty ())
    {
      this->label_.set (LabelTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "persistent" && n.namespace_ ().empty ())
    {
      this->persistent_.set (PersistentTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "useLetter" && n.namespace_ ().empty ())
    {
      this->useLetter_.set (UseLetterTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "letter" && n.namespace_ ().empty ())
    {
      this->letter_.set (LetterTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "disabled" && n.namespace_ ().empty ())
    {
      this->disabled_.set (DisabledTraits::create (i, f, this));
      continue;
    }
  }

  if (!path_.present ())
  {
    throw ::xsd::cxx::tree::expected_attribute< char > (
      "path",
      "");
  }

  if (!persistent_.present ())
  {
    throw ::xsd::cxx::tree::expected_attribute< char > (
      "persistent",
      "");
  }

  if (!useLetter_.present ())
  {
    throw ::xsd::cxx::tree::expected_attribute< char > (
      "useLetter",
      "");
  }

  if (!letter_.present ())
  {
    throw ::xsd::cxx::tree::expected_attribute< char > (
      "letter",
      "");
  }
}

Properties_t* Properties_t::
_clone (::xml_schema::Flags f,
        ::xml_schema::Container* c) const
{
  return new class Properties_t (*this, f, c);
}

Properties_t& Properties_t::
operator= (const Properties_t& x)
{
  if (this != &x)
  {
    static_cast< ::xml_schema::Type& > (*this) = x;
    this->action_ = x.action_;
    this->thisDrive_ = x.thisDrive_;
    this->allDrives_ = x.allDrives_;
    this->userName_ = x.userName_;
    this->cpassword_ = x.cpassword_;
    this->path_ = x.path_;
    this->label_ = x.label_;
    this->persistent_ = x.persistent_;
    this->useLetter_ = x.useLetter_;
    this->letter_ = x.letter_;
    this->disabled_ = x.disabled_;
  }

  return *this;
}

Properties_t::
~Properties_t ()
{
}

static
const ::xsd::cxx::tree::type_factory_initializer< 0, char, Properties_t >
_xsd_Properties_t_type_factory_init (
  "Properties_t",
  "");

// Drive_t
//

Drive_t::
Drive_t (const ClsidType& clsid,
         const NameType& name,
         const UidType& uid)
: ::xml_schema::Type (),
  Properties_ (this),
  clsid_ (clsid, this),
  name_ (name, this),
  image_ (this),
  changed_ (this),
  uid_ (uid, this),
  desc_ (this),
  bypassErrors_ (this),
  userContext_ (this),
  removePolicy_ (this),
  status_ (this)
{
}

Drive_t::
Drive_t (const Drive_t& x,
         ::xml_schema::Flags f,
         ::xml_schema::Container* c)
: ::xml_schema::Type (x, f, c),
  Properties_ (x.Properties_, f, this),
  clsid_ (x.clsid_, f, this),
  name_ (x.name_, f, this),
  image_ (x.image_, f, this),
  changed_ (x.changed_, f, this),
  uid_ (x.uid_, f, this),
  desc_ (x.desc_, f, this),
  bypassErrors_ (x.bypassErrors_, f, this),
  userContext_ (x.userContext_, f, this),
  removePolicy_ (x.removePolicy_, f, this),
  status_ (x.status_, f, this)
{
}

Drive_t::
Drive_t (const ::xercesc::DOMElement& e,
         ::xml_schema::Flags f,
         ::xml_schema::Container* c)
: ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
  Properties_ (this),
  clsid_ (this),
  name_ (this),
  image_ (this),
  changed_ (this),
  uid_ (this),
  desc_ (this),
  bypassErrors_ (this),
  userContext_ (this),
  removePolicy_ (this),
  status_ (this)
{
  if ((f & ::xml_schema::Flags::base) == 0)
  {
    ::xsd::cxx::xml::dom::parser< char > p (e, true, false, true);
    this->parse (p, f);
  }
}

void Drive_t::
parse (::xsd::cxx::xml::dom::parser< char >& p,
       ::xml_schema::Flags f)
{
  for (; p.more_content (); p.next_content (false))
  {
    const ::xercesc::DOMElement& i (p.cur_element ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    // Properties
    //
    {
      ::std::unique_ptr< ::xsd::cxx::tree::type > tmp (
        ::xsd::cxx::tree::type_factory_map_instance< 0, char > ().create (
          "Properties",
          "",
          &::xsd::cxx::tree::factory_impl< PropertiesType >,
          false, true, i, n, f, this));

      if (tmp.get () != 0)
      {
        ::std::unique_ptr< PropertiesType > r (
          dynamic_cast< PropertiesType* > (tmp.get ()));

        if (r.get ())
          tmp.release ();
        else
          throw ::xsd::cxx::tree::not_derived< char > ();

        this->Properties_.push_back (::std::move (r));
        continue;
      }
    }

    break;
  }

  while (p.more_attributes ())
  {
    const ::xercesc::DOMAttr& i (p.next_attribute ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    if (n.name () == "clsid" && n.namespace_ ().empty ())
    {
      this->clsid_.set (ClsidTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "name" && n.namespace_ ().empty ())
    {
      this->name_.set (NameTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "image" && n.namespace_ ().empty ())
    {
      this->image_.set (ImageTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "changed" && n.namespace_ ().empty ())
    {
      this->changed_.set (ChangedTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "uid" && n.namespace_ ().empty ())
    {
      this->uid_.set (UidTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "desc" && n.namespace_ ().empty ())
    {
      this->desc_.set (DescTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "bypassErrors" && n.namespace_ ().empty ())
    {
      this->bypassErrors_.set (BypassErrorsTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "userContext" && n.namespace_ ().empty ())
    {
      this->userContext_.set (UserContextTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "removePolicy" && n.namespace_ ().empty ())
    {
      this->removePolicy_.set (RemovePolicyTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "status" && n.namespace_ ().empty ())
    {
      this->status_.set (StatusTraits::create (i, f, this));
      continue;
    }
  }

  if (!clsid_.present ())
  {
    throw ::xsd::cxx::tree::expected_attribute< char > (
      "clsid",
      "");
  }

  if (!name_.present ())
  {
    throw ::xsd::cxx::tree::expected_attribute< char > (
      "name",
      "");
  }

  if (!uid_.present ())
  {
    throw ::xsd::cxx::tree::expected_attribute< char > (
      "uid",
      "");
  }
}

Drive_t* Drive_t::
_clone (::xml_schema::Flags f,
        ::xml_schema::Container* c) const
{
  return new class Drive_t (*this, f, c);
}

Drive_t& Drive_t::
operator= (const Drive_t& x)
{
  if (this != &x)
  {
    static_cast< ::xml_schema::Type& > (*this) = x;
    this->Properties_ = x.Properties_;
    this->clsid_ = x.clsid_;
    this->name_ = x.name_;
    this->image_ = x.image_;
    this->changed_ = x.changed_;
    this->uid_ = x.uid_;
    this->desc_ = x.desc_;
    this->bypassErrors_ = x.bypassErrors_;
    this->userContext_ = x.userContext_;
    this->removePolicy_ = x.removePolicy_;
    this->status_ = x.status_;
  }

  return *this;
}

Drive_t::
~Drive_t ()
{
}

static
const ::xsd::cxx::tree::type_factory_initializer< 0, char, Drive_t >
_xsd_Drive_t_type_factory_init (
  "Drive_t",
  "");

// Drives
//

Drives::
Drives (const ClsidType& clsid)
: ::xml_schema::Type (),
  Drive_ (this),
  clsid_ (clsid, this),
  disabled_ (this)
{
}

Drives::
Drives (const Drives& x,
        ::xml_schema::Flags f,
        ::xml_schema::Container* c)
: ::xml_schema::Type (x, f, c),
  Drive_ (x.Drive_, f, this),
  clsid_ (x.clsid_, f, this),
  disabled_ (x.disabled_, f, this)
{
}

Drives::
Drives (const ::xercesc::DOMElement& e,
        ::xml_schema::Flags f,
        ::xml_schema::Container* c)
: ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
  Drive_ (this),
  clsid_ (this),
  disabled_ (this)
{
  if ((f & ::xml_schema::Flags::base) == 0)
  {
    ::xsd::cxx::xml::dom::parser< char > p (e, true, false, true);
    this->parse (p, f);
  }
}

void Drives::
parse (::xsd::cxx::xml::dom::parser< char >& p,
       ::xml_schema::Flags f)
{
  for (; p.more_content (); p.next_content (false))
  {
    const ::xercesc::DOMElement& i (p.cur_element ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    // Drive
    //
    {
      ::std::unique_ptr< ::xsd::cxx::tree::type > tmp (
        ::xsd::cxx::tree::type_factory_map_instance< 0, char > ().create (
          "Drive",
          "",
          &::xsd::cxx::tree::factory_impl< DriveType >,
          false, true, i, n, f, this));

      if (tmp.get () != 0)
      {
        ::std::unique_ptr< DriveType > r (
          dynamic_cast< DriveType* > (tmp.get ()));

        if (r.get ())
          tmp.release ();
        else
          throw ::xsd::cxx::tree::not_derived< char > ();

        this->Drive_.push_back (::std::move (r));
        continue;
      }
    }

    break;
  }

  while (p.more_attributes ())
  {
    const ::xercesc::DOMAttr& i (p.next_attribute ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    if (n.name () == "clsid" && n.namespace_ ().empty ())
    {
      this->clsid_.set (ClsidTraits::create (i, f, this));
      continue;
    }

    if (n.name () == "disabled" && n.namespace_ ().empty ())
    {
      this->disabled_.set (DisabledTraits::create (i, f, this));
      continue;
    }
  }

  if (!clsid_.present ())
  {
    throw ::xsd::cxx::tree::expected_attribute< char > (
      "clsid",
      "");
  }
}

Drives* Drives::
_clone (::xml_schema::Flags f,
        ::xml_schema::Container* c) const
{
  return new class Drives (*this, f, c);
}

Drives& Drives::
operator= (const Drives& x)
{
  if (this != &x)
  {
    static_cast< ::xml_schema::Type& > (*this) = x;
    this->Drive_ = x.Drive_;
    this->clsid_ = x.clsid_;
    this->disabled_ = x.disabled_;
  }

  return *this;
}

Drives::
~Drives ()
{
}

#include <ostream>

#include <xsd/cxx/tree/std-ostream-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::std_ostream_plate< 0, char >
  std_ostream_plate_init;
}

::std::ostream&
operator<< (::std::ostream& o, const Properties_t& i)
{
  if (i.action ())
  {
    o << ::std::endl << "action: " << *i.action ();
  }

  if (i.thisDrive ())
  {
    o << ::std::endl << "thisDrive: " << *i.thisDrive ();
  }

  if (i.allDrives ())
  {
    o << ::std::endl << "allDrives: " << *i.allDrives ();
  }

  if (i.userName ())
  {
    o << ::std::endl << "userName: " << *i.userName ();
  }

  if (i.cpassword ())
  {
    o << ::std::endl << "cpassword: " << *i.cpassword ();
  }

  o << ::std::endl << "path: " << i.path ();
  if (i.label ())
  {
    o << ::std::endl << "label: " << *i.label ();
  }

  o << ::std::endl << "persistent: " << i.persistent ();
  o << ::std::endl << "useLetter: " << i.useLetter ();
  o << ::std::endl << "letter: " << i.letter ();
  if (i.disabled ())
  {
    o << ::std::endl << "disabled: " << *i.disabled ();
  }

  return o;
}

static
const ::xsd::cxx::tree::std_ostream_initializer< 0, char, Properties_t >
_xsd_Properties_t_std_ostream_init;

::std::ostream&
operator<< (::std::ostream& o, const Drive_t& i)
{
  {
    ::xsd::cxx::tree::std_ostream_map< char >& om (
      ::xsd::cxx::tree::std_ostream_map_instance< 0, char > ());

    for (Drive_t::PropertiesConstIterator
         b (i.Properties ().begin ()), e (i.Properties ().end ());
         b != e; ++b)
    {
      o << ::std::endl << "Properties: ";
      om.insert (o, *b);
    }
  }

  o << ::std::endl << "clsid: " << i.clsid ();
  o << ::std::endl << "name: " << i.name ();
  if (i.image ())
  {
    o << ::std::endl << "image: " << *i.image ();
  }

  if (i.changed ())
  {
    o << ::std::endl << "changed: " << *i.changed ();
  }

  o << ::std::endl << "uid: " << i.uid ();
  if (i.desc ())
  {
    o << ::std::endl << "desc: " << *i.desc ();
  }

  if (i.bypassErrors ())
  {
    o << ::std::endl << "bypassErrors: " << *i.bypassErrors ();
  }

  if (i.userContext ())
  {
    o << ::std::endl << "userContext: " << *i.userContext ();
  }

  if (i.removePolicy ())
  {
    o << ::std::endl << "removePolicy: " << *i.removePolicy ();
  }

  if (i.status ())
  {
    o << ::std::endl << "status: " << *i.status ();
  }

  return o;
}

static
const ::xsd::cxx::tree::std_ostream_initializer< 0, char, Drive_t >
_xsd_Drive_t_std_ostream_init;

::std::ostream&
operator<< (::std::ostream& o, const Drives& i)
{
  {
    ::xsd::cxx::tree::std_ostream_map< char >& om (
      ::xsd::cxx::tree::std_ostream_map_instance< 0, char > ());

    for (Drives::DriveConstIterator
         b (i.Drive ().begin ()), e (i.Drive ().end ());
         b != e; ++b)
    {
      o << ::std::endl << "Drive: ";
      om.insert (o, *b);
    }
  }

  o << ::std::endl << "clsid: " << i.clsid ();
  if (i.disabled ())
  {
    o << ::std::endl << "disabled: " << *i.disabled ();
  }

  return o;
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

::std::unique_ptr< ::Drives >
Drives_ (const ::std::string& u,
         ::xml_schema::Flags f,
         const ::xml_schema::Properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::Flags::dont_initialize) == 0,
    (f & ::xml_schema::Flags::keep_dom) == 0);

  ::xsd::cxx::tree::error_handler< char > h;

  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      u, h, p, f));

  h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

  return ::std::unique_ptr< ::Drives > (
    ::Drives_ (
      std::move (d), f | ::xml_schema::Flags::own_dom, p));
}

::std::unique_ptr< ::Drives >
Drives_ (const ::std::string& u,
         ::xml_schema::ErrorHandler& h,
         ::xml_schema::Flags f,
         const ::xml_schema::Properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::Flags::dont_initialize) == 0,
    (f & ::xml_schema::Flags::keep_dom) == 0);

  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      u, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  return ::std::unique_ptr< ::Drives > (
    ::Drives_ (
      std::move (d), f | ::xml_schema::Flags::own_dom, p));
}

::std::unique_ptr< ::Drives >
Drives_ (const ::std::string& u,
         ::xercesc::DOMErrorHandler& h,
         ::xml_schema::Flags f,
         const ::xml_schema::Properties& p)
{
  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      u, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  return ::std::unique_ptr< ::Drives > (
    ::Drives_ (
      std::move (d), f | ::xml_schema::Flags::own_dom, p));
}

::std::unique_ptr< ::Drives >
Drives_ (::std::istream& is,
         ::xml_schema::Flags f,
         const ::xml_schema::Properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::Flags::dont_initialize) == 0,
    (f & ::xml_schema::Flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is);
  return ::Drives_ (isrc, f, p);
}

::std::unique_ptr< ::Drives >
Drives_ (::std::istream& is,
         ::xml_schema::ErrorHandler& h,
         ::xml_schema::Flags f,
         const ::xml_schema::Properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::Flags::dont_initialize) == 0,
    (f & ::xml_schema::Flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is);
  return ::Drives_ (isrc, h, f, p);
}

::std::unique_ptr< ::Drives >
Drives_ (::std::istream& is,
         ::xercesc::DOMErrorHandler& h,
         ::xml_schema::Flags f,
         const ::xml_schema::Properties& p)
{
  ::xsd::cxx::xml::sax::std_input_source isrc (is);
  return ::Drives_ (isrc, h, f, p);
}

::std::unique_ptr< ::Drives >
Drives_ (::std::istream& is,
         const ::std::string& sid,
         ::xml_schema::Flags f,
         const ::xml_schema::Properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::Flags::dont_initialize) == 0,
    (f & ::xml_schema::Flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
  return ::Drives_ (isrc, f, p);
}

::std::unique_ptr< ::Drives >
Drives_ (::std::istream& is,
         const ::std::string& sid,
         ::xml_schema::ErrorHandler& h,
         ::xml_schema::Flags f,
         const ::xml_schema::Properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::Flags::dont_initialize) == 0,
    (f & ::xml_schema::Flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
  return ::Drives_ (isrc, h, f, p);
}

::std::unique_ptr< ::Drives >
Drives_ (::std::istream& is,
         const ::std::string& sid,
         ::xercesc::DOMErrorHandler& h,
         ::xml_schema::Flags f,
         const ::xml_schema::Properties& p)
{
  ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
  return ::Drives_ (isrc, h, f, p);
}

::std::unique_ptr< ::Drives >
Drives_ (::xercesc::InputSource& i,
         ::xml_schema::Flags f,
         const ::xml_schema::Properties& p)
{
  ::xsd::cxx::tree::error_handler< char > h;

  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      i, h, p, f));

  h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

  return ::std::unique_ptr< ::Drives > (
    ::Drives_ (
      std::move (d), f | ::xml_schema::Flags::own_dom, p));
}

::std::unique_ptr< ::Drives >
Drives_ (::xercesc::InputSource& i,
         ::xml_schema::ErrorHandler& h,
         ::xml_schema::Flags f,
         const ::xml_schema::Properties& p)
{
  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      i, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  return ::std::unique_ptr< ::Drives > (
    ::Drives_ (
      std::move (d), f | ::xml_schema::Flags::own_dom, p));
}

::std::unique_ptr< ::Drives >
Drives_ (::xercesc::InputSource& i,
         ::xercesc::DOMErrorHandler& h,
         ::xml_schema::Flags f,
         const ::xml_schema::Properties& p)
{
  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      i, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  return ::std::unique_ptr< ::Drives > (
    ::Drives_ (
      std::move (d), f | ::xml_schema::Flags::own_dom, p));
}

::std::unique_ptr< ::Drives >
Drives_ (const ::xercesc::DOMDocument& doc,
         ::xml_schema::Flags f,
         const ::xml_schema::Properties& p)
{
  if (f & ::xml_schema::Flags::keep_dom)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

    return ::std::unique_ptr< ::Drives > (
      ::Drives_ (
        std::move (d), f | ::xml_schema::Flags::own_dom, p));
  }

  const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
  const ::xsd::cxx::xml::qualified_name< char > n (
    ::xsd::cxx::xml::dom::name< char > (e));

  if (n.name () == "Drives" &&
      n.namespace_ () == "")
  {
    ::std::unique_ptr< ::Drives > r (
      ::xsd::cxx::tree::traits< ::Drives, char >::create (
        e, f, 0));
    return r;
  }

  throw ::xsd::cxx::tree::unexpected_element < char > (
    n.name (),
    n.namespace_ (),
    "Drives",
    "");
}

::std::unique_ptr< ::Drives >
Drives_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
         ::xml_schema::Flags f,
         const ::xml_schema::Properties&)
{
  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > c (
    ((f & ::xml_schema::Flags::keep_dom) &&
     !(f & ::xml_schema::Flags::own_dom))
    ? static_cast< ::xercesc::DOMDocument* > (d->cloneNode (true))
    : 0);

  ::xercesc::DOMDocument& doc (c.get () ? *c : *d);
  const ::xercesc::DOMElement& e (*doc.getDocumentElement ());

  const ::xsd::cxx::xml::qualified_name< char > n (
    ::xsd::cxx::xml::dom::name< char > (e));

  if (f & ::xml_schema::Flags::keep_dom)
    doc.setUserData (::xml_schema::dom::tree_node_key,
                     (c.get () ? &c : &d),
                     0);

  if (n.name () == "Drives" &&
      n.namespace_ () == "")
  {
    ::std::unique_ptr< ::Drives > r (
      ::xsd::cxx::tree::traits< ::Drives, char >::create (
        e, f, 0));
    return r;
  }

  throw ::xsd::cxx::tree::unexpected_element < char > (
    n.name (),
    n.namespace_ (),
    "Drives",
    "");
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

