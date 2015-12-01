/*
    This file has been generated by bvtidl.pl. DO NOT MODIFY!
*/
#ifndef __CPP_BVTHEAD_H__
#define __CPP_BVTHEAD_H__

#include <string>
#include <bvt_cpp/bvt_retval.h>
#include <bvt_cpp/bvt_ping.h>

namespace BVTSDK
{

/** A head consists of a group of co-planar transducers which are
 * operated simultaneously to produce (ultimately) a single 2d
 * image.  The Head object provides functions to change the 
 * range window as well as produce pings.
 */
class Head
{
public:
	/// Create the object
	Head()
	{ m_ptr = NULL; }

#ifndef DOXY_IGNORE
	Head(BVTHead ptr)
	{ m_ptr = ptr; }

	operator BVTHead()
	{ return m_ptr; }
	operator BVTHead*()
	{ return &m_ptr; }
	operator const BVTHead() const
	{ return m_ptr; }
#endif

	/** Retrieves a copy of a the name of the head. The head name is currently
	 * set only at the factory, and is simply "Head" on many sonars. Only special
	 * order sonars with multiple heads are likely to have a different name.<br>
	 * The length of the name has no actual limit, though 80 characters
	 * would seem to be more than enough.
	 * \param buffer buffer to hold the null-terminated string to be passed back 
	 * \param buffer_size total number of characters the passed buffer can hold 
	 */
	RetVal GetHeadName(char* buffer, int buffer_size)
	{
		return BVTHead_GetHeadName( m_ptr, buffer, buffer_size );
	}

	/** Set the range to be acquired.
	 * \param start Start range in meters 
	 * \param stop Stop range in meters 
	 */
	RetVal SetRange(float start, float stop)
	{
		return BVTHead_SetRange( m_ptr, start, stop );
	}

	/** Retrieve the current starting range in meters
	 */
	float GetStartRange()
	{
		return BVTHead_GetStartRange( m_ptr );
	}

	/** Retrieve the current stopping range in meters.
	 */
	float GetStopRange()
	{
		return BVTHead_GetStopRange( m_ptr );
	}

	/** Return the minimum allowable range for this sonar
	 */
	float GetMinimumRange()
	{
		return BVTHead_GetMinimumRange( m_ptr );
	}

	/** Return the maximum allowable range for this sonar
	 */
	float GetMaximumRange()
	{
		return BVTHead_GetMaximumRange( m_ptr );
	}

	static const int FLUID_SALTWATER	= 0;

	static const int FLUID_FRESHWATER	= 1;

	static const int FLUID_OTHER	= 2;

	/** Return the type of water the head is in.  The returned value will correspond to 
	 * one of the FLUID_* constants.
	 */
	int GetFluidType()
	{
		return BVTHead_GetFluidType( m_ptr );
	}

	/** Set the type of water the head is in
	 * \param fluid The fluid type (one of the FLUID_* constants) 
	 */
	RetVal SetFluidType(int fluid)
	{
		return BVTHead_SetFluidType( m_ptr, fluid );
	}

	/** Return the speed of sound in water
	 */
	int GetSoundSpeed()
	{
		return BVTHead_GetSoundSpeed( m_ptr );
	}

	/** Set the speed of sound in water
	 * \param speed Sound speed in water 
	 */
	RetVal SetSoundSpeed(int speed)
	{
		return BVTHead_SetSoundSpeed( m_ptr, speed );
	}

	/** Return the additional analog gain in dB
	 */
	float GetGainAdjustment()
	{
		return BVTHead_GetGainAdjustment( m_ptr );
	}

	/** Set the additional analog gain. Note: Some systems don't
	 * support gain adjustment.
	 * \param gain Additional analog gain in dB 
	 */
	RetVal SetGainAdjustment(float gain)
	{
		return BVTHead_SetGainAdjustment( m_ptr, gain );
	}

	/** Return the time variable gain in dB/meter
	 */
	float GetTVGSlope()
	{
		return BVTHead_GetTVGSlope( m_ptr );
	}

	/** Set the  time variable analog gain. Note: Some systems 
	 * don't support TVG
	 * \param tvg Time variable gain in dB/meter 
	 */
	RetVal SetTVGSlope(float tvg)
	{
		return BVTHead_SetTVGSlope( m_ptr, tvg );
	}

	/** Return the center frequency(in Hz) of this head.
	 */
	int GetCenterFreq()
	{
		return BVTHead_GetCenterFreq( m_ptr );
	}

	/** Return the number of pings 'in' this head
	 * A head attached to a file might have more than one ping recorded.  However, a networked sonar
	 * will only have a single ping.
	 */
	int GetPingCount()
	{
		return BVTHead_GetPingCount( m_ptr );
	}

	/** Retrieve a Ping from the Head
	 * If ping_num is less than 0, return the next ping in the file. Otherwise, load the specified ping.  
	 * If the Head is attached to a 'live' sonar (network), then GetPing always acquires a new ping.
	 * \param ping_num The ping number to return 
	 * \param ping The returned Ping object
	 */
	RetVal GetPing(int ping_num, Ping* ping)
	{
		return BVTHead_GetPing( m_ptr, ping_num, *ping );
	}

	/** Write a ping to a file.
	 * \param ping The ping to write out 
	 */
	RetVal PutPing(const Ping& ping)
	{
		return BVTHead_PutPing( m_ptr, ping );
	}

	/** Turn off image processing	
	 */
	static const int RES_OFF	= 0;

	/** Process at low resolution 
	 */
	static const int RES_LOW	= 1;

	/** Process at med resolution 
	 */
	static const int RES_MED	= 2;

	/** Process at high resolution 
	 */
	static const int RES_HIGH	= 3;

	/** Select a good res for the current range automatically 
	 */
	static const int RES_AUTO	= 4;

	/** Set the image processing resolution. The RES_AUTO setting is highly
	 * recommended, as it adapts via a formula according to the stop range,
	 * whereas the other ranges are fixed values, and should only be used
	 * in specialized cases, such as requesting high resolution for longer
	 * distances (which will increase the processing time required to 
	 * create the image).
	 * \param res Resolution constant (RES_*)
	 */
	RetVal SetImageRes(int res)
	{
		return BVTHead_SetImageRes( m_ptr, res );
	}

	/** Requests a range resolution for R-Theta images. Also affects the
	 * range resolution for RangeData. Note that the exact range resolution
	 * may not be available, and the closest resolution will be set. The
	 * actual resolution can be obtained by querying the returned image
	 * or RangeData object.
	 * \param resolution_in_meters Range resolution, in meters 
	 */
	RetVal SetRangeResolution(float resolution_in_meters)
	{
		return BVTHead_SetRangeResolution( m_ptr, resolution_in_meters );
	}

	/** Set the requested out image size
	 * The processing code will attempt to process images at the specified size.  However, it doesn't
	 * guarantee that the final output will match this size.
	 * \param height The requested height 
	 * \param width The requested width 
	 */
	RetVal SetImageReqSize(int height, int width)
	{
		return BVTHead_SetImageReqSize( m_ptr, height, width );
	}

	/** NOTE: this option is only valid for some sonars, in specific circumstances,
	 * and should only be used on advice from the factory. <br>
	 * By default, beamforming is done on the local system.  If you call this
	 * function with enable=true, the SDK will request that the remote sonar
	 * handle the majority of the beamforming. This operation applies the next 
	 * time GetPing is called. <br>
	 * \param enable Enable/Disable remote beamformer. (using 1 or 0 to enable or disable) 
	 */
	RetVal SetRemoteBeamForming(int enable)
	{
		return BVTHead_SetRemoteBeamForming( m_ptr, enable );
	}

	/** NOTE: this option is only valid for some sonars, in specific circumstances,
	 * and should only be used on advice from the factory. <br>
	 * By default, the sonar sends data suitable for saving to a .son file.  If you 
	 * are not saving files, AND are recieving processed data thru setting one of
	 * the other options, you can call this function with enable=false to reduce the 
	 * amount of network bandwidth needed. . This operation applies the next time GetPing 
	 * is called.
	 * \param enable Enable/Disable raw ping data. (using 1 or 0 to enable or disable) 
	 */
	RetVal SetRawDataSending(int enable)
	{
		return BVTHead_SetRawDataSending( m_ptr, enable );
	}

	/** NOTE: this option is only valid for some sonars, in specific circumstances,
	 * and should only be used on advice from the factory. <br>
	 * By default, image forming is done on the local system. 
	 * If you call this function with en=true, the SDK will request that
	 * the remote sonar handle the image forming. This option is slightly
	 * different than remote beam-forming, with all processing done on
	 * the sonar, and only the complete image sent over the network connection.
	 * This operation applies the next time GetPing is called. <br>
	 * \param enable Enable/Disable remote image forming. (using 1 or 0 to enable or disable) 
	 */
	RetVal SetRemoteImageForming(int enable)
	{
		return BVTHead_SetRemoteImageForming( m_ptr, enable );
	}

	/** Output a cartesian image 
	 */
	static const int IMAGE_XY	= 0;

	/** Output a Range/Theta image 
	 */
	static const int IMAGE_RTHETA	= 1;

	/** Set the type of image output
	 * \param type Image type constant (IMAGE_*) 
	 */
	RetVal SetImageType(int type)
	{
		return BVTHead_SetImageType( m_ptr, type );
	}

	/** Return the filter flags.
	 */
	int GetImageFilterFlags()
	{
		return BVTHead_GetImageFilterFlags( m_ptr );
	}

	/** Set the filter flags.
	 * \param flags Image filter flags (bit field) 
	 */
	RetVal SetImageFilterFlags(int flags)
	{
		return BVTHead_SetImageFilterFlags( m_ptr, flags );
	}

	/** ** EXPERIMENTAL **  Sets the intensity value below which data is
	 * considered to be noise. Values above this threshold are included in
	 * the algorithm which attempts to determine the target edge. This is
	 * NOT a simple threshold above which the first value encountered is
	 * considered the target edge. This is the same intensity value returned
	 * in a MagImage, with a range of an unsigned 16-bit integer.
	 * If not set, the default is currently set to 1000. <br>
	 * NOTE: This only applies to specialized BlueView sonars.
	 * \param noise_threshold Threshold below which is considered noise 
	 */
	RetVal SetRangeDataThreshold(unsigned short noise_threshold)
	{
		return BVTHead_SetRangeDataThreshold( m_ptr, noise_threshold );
	}

	/** By default, the sonar transmits pings.  This function allows the user to 
	 * disable transmit.  This can be useful to get background noise measurements.
	 * Note that this is not implemented on all sonars.
	 * \param enableTx If 0, disable the sonar transmission of pings.
	 */
	RetVal SetTxEnable(int enableTx)
	{
		return BVTHead_SetTxEnable( m_ptr, enableTx );
	}

	/** ** Preliminary support - may change in later SDK versions ** <br>
	 * Position of the sonar positioner relative to the boat.
	 * \param X_axis_degrees rotation about X axis 
	 * \param Y_axis_degrees rotation about Y axis 
	 * \param Z_axis_degrees rotation about Z axis 
	 */
	RetVal GetMountingOrientation(double* X_axis_degrees, double* Y_axis_degrees, double* Z_axis_degrees)
	{
		return BVTHead_GetMountingOrientation( m_ptr, X_axis_degrees, Y_axis_degrees, Z_axis_degrees );
	}

	/** ** Preliminary support - may change in later SDK versions ** <br>
	 * Position of the sonar positioner relative to the boat.
	 * \param X_axis_degrees rotation about X axis 
	 * \param Y_axis_degrees rotation about Y axis 
	 * \param Z_axis_degrees rotation about Z axis 
	 */
	RetVal SetMountingOrientation(double X_axis_degrees, double Y_axis_degrees, double Z_axis_degrees)
	{
		return BVTHead_SetMountingOrientation( m_ptr, X_axis_degrees, Y_axis_degrees, Z_axis_degrees );
	}


private:
	BVTHead m_ptr;
};
}

#endif