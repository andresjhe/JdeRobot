/*
 *  Copyright (C) 1997-2011 JDERobot Developers Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *  Authors : Julio Vega <julio.vega@urjc.es>,
 *
 */

#ifndef INTROROB_CONTROLLER_H
#define INTROROB_CONTROLLER_H

#include <string>
#include <iostream>
#include <colorspaces/colorspacesmm.h>
#include <jderobot/motors.h>
#include <jderobot/ptmotors.h>
#include <jderobot/encoders.h>
#include <jderobot/ptencoders.h>
#include <jderobot/laser.h>
#include <pthread.h>
#include "pioneer.h"
#include "drawarea.h"

namespace introrob {
  class Controller {
		public:
			Controller (jderobot::MotorsPrx mprx, jderobot::EncodersPrx eprx, jderobot::LaserPrx lprx, jderobot::CameraPrx cprx1, jderobot::CameraPrx cprx2, jderobot::PTMotorsPrx ptmprx1, jderobot::PTEncodersPrx pteprx1, jderobot::PTMotorsPrx ptmprx2, jderobot::PTEncodersPrx pteprx2);
		  virtual ~Controller();
		  
		  std::string getGladePath();

			void drawScene();

			void playMotors ();
			void stopMotors ();
			void goLeft ();
			void goRight ();
			void goUp ();
			void goDown ();

			/* v: velocidad lineal (mm./s.) a comandar al robot */
			void setV (float v);

			/* w: velocidad rotacional (deg./s.) a comandar al robot */
			void setW (float w);

			/* latitude: posición tilt (deg.) a comandar al cuello mecánico 
			longitude: posición pan (deg.) a comandar al cuello mecánico */
			void setPT1 (float latitude, float longitude);

			/* latitude: posición tilt (deg.) a comandar al cuello mecánico 
			longitude: posición pan (deg.) a comandar al cuello mecánico */
			void setPT2 (float latitude, float longitude);

			void updatePioneerStatus ();

			void getCameraData(unsigned char **image1, unsigned char **image2);

			static const float V_MOTOR;
			static const float W_MOTOR;

			jderobot::EncodersDataPtr ed;
			jderobot::LaserDataPtr ld;
			jderobot::ImageDataPtr data1;
			jderobot::ImageDataPtr data2;
			colorspaces::Image* image1;
			colorspaces::Image* image2;

		private:
			std::string gladepath;
			jderobot::MotorsPrx mprx;
			jderobot::EncodersPrx eprx;
			jderobot::LaserPrx lprx;
			jderobot::CameraPrx cprx1;
			jderobot::CameraPrx cprx2;
			jderobot::PTMotorsPrx ptmprx1;
			jderobot::PTEncodersPrx pteprx1;
			jderobot::PTMotorsPrx ptmprx2;
			jderobot::PTEncodersPrx pteprx2;
			pthread_mutex_t mutex;
			unsigned char *myImage1;
			unsigned char *myImage2;
  };
} // namespace

#endif /*INTROROB_CONTROLLER_H*/