module DataProducts {
    struct BmpSample {
        timestamp  : Fw.TimeValue
        temperature : F32
        altitude : F32
        pressure : F32
    }

    @ Component for F Prime FSW framework.
    passive component BmpManager {

        ##############################################################################
        #### Uncomment the following examples to start customizing your component ####
        ##############################################################################

        product record Bmp280ProductRecord: BmpSample

        sync input port run: Svc.Sched
        sync input port Bmp280DataIn: Bmp280.Bmp280DataOut
        
        product container Bmp280DataContainer

        product get port Bmp280ProductGet
        product send port Bmp280ProductSend
        
        @ Event 
        event Bmp280ProducerMemoryFailure(allocationSize : FwSizeType) \
            severity warning high id 0 \
            format "Memory allocation of size {} for data product container failed" \
            throttle 2

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Enables command handling
        import Fw.Command

        @ Enables event handling
        import Fw.Event

        @ Enables telemetry channels handling
        import Fw.Channel

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut


    }
}