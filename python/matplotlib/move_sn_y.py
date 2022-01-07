def move_sn_y(offs=0, dig=0, side='left', omit_last=False):
    """Move scientific notation exponent from top to the side.
    
    Additionally, one can set the number of digits after the comma
    for the y-ticks, hence if it should state 1, 1.0, 1.00 and so forth.

    Parameters
    ----------
    offs : float, optional; <0>
        Horizontal movement additional to default.
    dig : int, optional; <0>
        Number of decimals after the comma.
    side : string, optional; {<'left'>, 'right'}
        To choose the side of the y-axis notation.
    omit_last : bool, optional; <False>
        If True, the top y-axis-label is omitted.

    Returns
    -------
    locs : list
        List of y-tick locations.

    Note
    ----
    This is kind of a non-satisfying hack, which should be handled more
    properly. But it works. Functions to look at for a better implementation:
    ax.ticklabel_format
    ax.yaxis.major.formatter.set_offset_string
    """

    # Get the ticks
    locs, _ = plt.yticks()

    # Put the last entry into a string, ensuring it is in scientific notation
    # E.g: 123456789 => '1.235e+08'
    llocs = '%.3e' % locs[-1]

    # Get the magnitude, hence the number after the 'e'
    # E.g: '1.235e+08' => 8
    yoff = int(str(llocs).split('e')[1])

    # If omit_last, remove last entry
    if omit_last:
        slocs = locs[:-1]
    else:
        slocs = locs

    # Set ticks to the requested precision
    form = r'$%.'+str(dig)+'f$'
    plt.yticks(locs, list(map(lambda x: form % x, slocs/(10**yoff))))

    # Define offset depending on the side
    if side == 'left':
        offs = -.18 - offs # Default left: -0.18
    elif side == 'right':
        offs = 1 + offs    # Default right: 1.0
        
    # Plot the exponent
    plt.text(offs, .98, r'$\times10^{%i}$' % yoff, transform =
            plt.gca().transAxes, verticalalignment='top')

    # Return the locs
    return locs
